#include "Vector2D.h"

Vector2D projected_pt_onto_line(Vector2D p, Vector2D v, Vector2D q)
{
	// the line is defined as p+t*v
	// where p is the point position on the line
	//       v is the directional vector along the line
	//       t is the scalar values

	// Compute the projected point of q on the line "p+t*v" 
	return Dot(q - p, v) / pow(v.Magnitude(v), 2) * v;
}
//
//float dist_btw_pt_line(Vector2D p, Vector2D v, Vector2D q)
//{
//	// compute the distance between the point p and the line "p+t*v"
//}
//
//bool same_side_of_plane(Vector3D a, Vector3D b, Vector3D c, Vector3D p, Vector3D q)
//{
//	// point a, b, c define the plane 
//	// Let's decide wheter point p and point q are on the same side of the plane
//
//}
//
//float dist_from_pt_to_plane(Vector3D a, Vector3D b, Vector3D c, Vector3D p)
//{
//	// point a, b, c define the plane 
//	// Compute the distance from point p to the plane
//
//}