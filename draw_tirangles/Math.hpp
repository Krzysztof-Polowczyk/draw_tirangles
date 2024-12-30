#pragma once // the fukc is this
#include <vector>
typedef struct { double x; double y; double z; } Vec1x3;
typedef struct { int R; int G; int B; } Color;
typedef struct { Vec1x3 a; Vec1x3 b; Vec1x3 c; Color color; } triangle;
typedef struct std::vector<std::vector<double>> mat;
typedef std::vector<triangle> mesh;

class Vecmath {
	public:
		static Vec1x3 addVec(Vec1x3& A, Vec1x3& B) {
			return { A.x + B.x, A.y + B.y, A.z + B.z };
		}
 

		static Vec1x3 mulVecbyNum(Vec1x3& iVec, double num) {
			return { iVec.x * num, iVec.y * num, iVec.z * num };
		}

		static Vec1x3 subVecbyVec(Vec1x3& A, Vec1x3& B) {
			return { A.x - B.x, A.y - B.y, A.z - B.z };
		}

		static Vec1x3 mulVecbyVecGOOD(Vec1x3& A, Vec1x3& B) {

			return 			{
							{A.x * B.x},
							{A.y * B.y},
							{A.z * B.z}
			};
		}
		// put swer words there
		static Vec1x3 mulVecbyVec(Vec1x3& A, Vec1x3& B) {
			return {
							{A.y * B.z - B.y * A.z},
							{A.z * B.x - B.z * A.x},
							{A.x * B.y - B.x * A.y}
			};
		}

		static double getLendgt(Vec1x3& A) {
			return sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
		}

		static Vec1x3 getUnit(Vec1x3& A) {
			float l = getLendgt(A);
			return { A.x / l, A.y / l, A.z / l };
		}

		static double dot(Vec1x3& A, Vec1x3& B) {
			return A.x * B.x + A.y * B.y + A.z * B.z;
		}

		static mat multiplyMat(mat& A, mat& B) {
			mat result = {};
			for (int s = 0; s < A.size(); s++) {
				std::vector<double> temp = {};
				result.push_back(temp);
				for (int j = 0; j < B[0].size(); j++) {
					double sum = 0;
					for (int i = 0; i < A[s].size(); i++) {
						sum += A[s][i] * B[i][j];
					}
					result[s].push_back(sum);
				}
			}
			return result;
		}

		static Vec1x3 multiplyMat(Vec1x3& i, mat& m) {
			Vec1x3 o = {};
			o.x = i.x * m[0][0] + i.y * m[1][0] + i.z * m[2][0] + m[3][0];
			o.y = i.x * m[0][1] + i.y * m[1][1] + i.z * m[2][1] + m[3][1];
			o.z = i.x * m[0][2] + i.y * m[1][2] + i.z * m[2][2] + m[3][2];
			float w = i.x * m[0][3] + i.y * m[1][3] + i.z * m[2][3] + m[3][3];

			if (w != 0.0)
			{
				o.x /= w; o.y /= w; o.z /= w;
			}
			return o;
		}

		static mat Matrix_PointAt(Vec1x3& pos, Vec1x3& target, Vec1x3& up)
		{
			// Calculate new forward direction
			Vec1x3 newForward = subVecbyVec(target, pos);
			newForward = getUnit(newForward);

			// Calculate new Up direction
			Vec1x3 a = mulVecbyNum(newForward, dot(up, newForward));
			Vec1x3 newUp = subVecbyVec(up, a);
			newUp = getUnit(newUp);

			// New Right direction is easy, its just cross product
			Vec1x3 newRight = mulVecbyVec(newUp, newForward);

			// Construct Dimensioning and Translation Matrix	
			mat matrix = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
			matrix[0][0] = newRight.x;	matrix[0][1] = newRight.y;	matrix[0][2] = newRight.z;	matrix[0][3] = 0.0f;
			matrix[1][0] = newUp.x;		matrix[1][1] = newUp.y;		matrix[1][2] = newUp.z;		matrix[1][3] = 0.0f;
			matrix[2][0] = newForward.x;	matrix[2][1] = newForward.y;	matrix[2][2] = newForward.z;	matrix[2][3] = 0.0f;
			matrix[3][0] = pos.x;			matrix[3][1] = pos.y;			matrix[3][2] = pos.z;			matrix[3][3] = 1.0f;
			return matrix;

		}

		static mat Matrix_QuickInverse(mat& m) // Only for Rotation/Translation Matrices
		{
			mat matrix = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
			matrix[0][0] = m[0][0]; matrix[0][1] = m[1][0]; matrix[0][2] = m[2][0]; matrix[0][3] = 0.0f;
			matrix[1][0] = m[0][1]; matrix[1][1] = m[1][1]; matrix[1][2] = m[2][1]; matrix[1][3] = 0.0f;
			matrix[2][0] = m[0][2]; matrix[2][1] = m[1][2]; matrix[2][2] = m[2][2]; matrix[2][3] = 0.0f;
			matrix[3][0] = -(m[3][0] * matrix[0][0] + m[3][1] * matrix[1][0] + m[3][2] * matrix[2][0]);
			matrix[3][1] = -(m[3][0] * matrix[0][1] + m[3][1] * matrix[1][1] + m[3][2] * matrix[2][1]);
			matrix[3][2] = -(m[3][0] * matrix[0][2] + m[3][1] * matrix[1][2] + m[3][2] * matrix[2][2]);
			matrix[3][3] = 1.0f;
			return matrix;
		}

		static Vec1x3 Vector_IntersectPlane(Vec1x3& plane_p, Vec1x3& plane_n, Vec1x3& lineStart, Vec1x3& lineEnd)
		{
			plane_n = getUnit(plane_n);
			double plane_d = -dot(plane_n, plane_p);
			double ad = dot(lineStart, plane_n);
			double bd = dot(lineEnd, plane_n);
			double t = (-plane_d - ad) / (bd - ad);
			Vec1x3 lineStartToEnd = subVecbyVec(lineEnd, lineStart);
			Vec1x3 lineToIntersect = mulVecbyNum(lineStartToEnd, t);
			return addVec(lineStart, lineToIntersect);
		}

		static int Triangle_ClipAgainstPlane(Vec1x3 plane_p, Vec1x3 plane_n, triangle& in_tri, triangle& out_tri1, triangle& out_tri2)
		{
			// Make sure plane normal is indeed normal
			plane_n = getUnit(plane_n);

			// Return signed shortest distance from point to plane, plane normal must be normalised
			auto dist = [&](Vec1x3 &p)
				{
					Vec1x3 n = getUnit(p);
					return (plane_n.x * p.x + plane_n.y * p.y + plane_n.z * p.z - dot(plane_n, plane_p));
				};

			// Create two temporary storage arrays to classify points either side of plane
			// If distance sign is positive, point lies on "inside" of plane
			Vec1x3* inside_points[3];  int nInsidePointCount = 0;
			Vec1x3* outside_points[3]; int nOutsidePointCount = 0;

			// Get signed distance of each point in triangle to plane
			double d0 = dist(in_tri.a);
			double d1 = dist(in_tri.b);
			double d2 = dist(in_tri.c);

			if (d0 >= 0) { inside_points[nInsidePointCount++] = &in_tri.a; }
			else { outside_points[nOutsidePointCount++] = &in_tri.a; }
			if (d1 >= 0) { inside_points[nInsidePointCount++] = &in_tri.b; }
			else { outside_points[nOutsidePointCount++] = &in_tri.b; }
			if (d2 >= 0) { inside_points[nInsidePointCount++] = &in_tri.c; }
			else { outside_points[nOutsidePointCount++] = &in_tri.c; }

			// Now classify triangle points, and break the input triangle into 
			// smaller output triangles if required. There are four possible
			// outcomes...

			if (nInsidePointCount == 0)
			{
				// All points lie on the outside of plane, so clip whole triangle
				// It ceases to exist

				return 0; // No returned triangles are valid
			}

			if (nInsidePointCount == 3)
			{
				// All points lie on the inside of plane, so do nothing
				// and allow the triangle to simply pass through
				out_tri1 = in_tri;

				return 1; // Just the one returned original triangle is valid
			}

			if (nInsidePointCount == 1 && nOutsidePointCount == 2)
			{
				// Triangle should be clipped. As two points lie outside
				// the plane, the triangle simply becomes a smaller triangle

				// Copy appearance info to new triangle
				out_tri1.color = in_tri.color;

				// The inside point is valid, so keep that...
				out_tri1.a = *inside_points[0];

				// but the two new points are at the locations where the 
				// original sides of the triangle (lines) intersect with the plane
				out_tri1.b = Vector_IntersectPlane(plane_p, plane_n, *inside_points[0], *outside_points[0]);
				out_tri1.c = Vector_IntersectPlane(plane_p, plane_n, *inside_points[0], *outside_points[1]);

				return 1; // Return the newly formed single triangle
			}

			if (nInsidePointCount == 2 && nOutsidePointCount == 1)
			{
				// Triangle should be clipped. As two points lie inside the plane,
				// the clipped triangle becomes a "quad". Fortunately, we can
				// represent a quad with two new triangles

				// Copy appearance info to new triangles
				out_tri1.color = in_tri.color;

				out_tri2.color = in_tri.color;

				// The first triangle consists of the two inside points and a new
				// point determined by the location where one side of the triangle
				// intersects with the plane
				out_tri1.a = *inside_points[0];
				out_tri1.b = *inside_points[1];
				out_tri1.c = Vector_IntersectPlane(plane_p, plane_n, *inside_points[0], *outside_points[0]);

				// The second triangle is composed of one of he inside points, a
				// new point determined by the intersection of the other side of the 
				// triangle and the plane, and the newly created point above
				out_tri2.a = *inside_points[1];
				out_tri2.b = out_tri1.c;
				out_tri2.c = Vector_IntersectPlane(plane_p, plane_n, *inside_points[1], *outside_points[0]);

				return 2; // Return two newly formed triangles which form a quad
			}
		}


		// if some thing is not wtight propobly matrixs do not align it will throw segmentation fault #good error handling

};
