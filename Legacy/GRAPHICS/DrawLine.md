# _DRAW_LINE

--- ns: GRAPHICS --- ## DRAW_LINE  // 0x6B7256074AE34680 0xB3426BCC void DRAW_LINE(float x1, float y1, float z1, float x2, float y2, float z2, int red, int green, int blue, int alpha);  This native draws a line between two vectors in the game world. It is typically used for visualizing paths or connections between points. The color of the line is specified by the red, green, and blue parameters, with alpha determining its opacity. This native should be called every frame for continuous rendering.  NativeDB Introduced: v323  ## Parameters * **x1**: The x-coordinate of the starting point of the line. * **y1**: The y-coordinate of the starting point of the line. * **z1**: The z-coordinate of the starting point of the line. * **x2**: The x-coordinate of the ending point of the line. * **y2**: The y-coordinate of the ending point of the line. * **z2**: The z-coordinate of the ending point of the line. * **red**: The red color component of the line (0 - 255). * **green**: The green color component of the line (0 - 255). * **blue**: The blue color component of the line (0 - 255). * **alpha**: The alpha value of the line (0 - 255).

### Parameters
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2
* int red
* int green
* int blue
* int alpha

### Return Value
* void

### Notes
* AP Hash: 0x0xB3426BCC
* Build: 323
* Draws a depth-tested line from one point to another.
----------------
x1, y1, z1 : Coordinates for the first point
x2, y2, z2 : Coordinates for the second point
r, g, b, alpha : Color with RGBA-Values
I recommend using a predefined function to call this.
[VB.NET]
Public Sub DrawLine(from As Vector3, [to] As Vector3, col As Color)
    [Function].Call(Hash.DRAW_LINE, from.X, from.Y, from.Z, [to].X, [to].Y, [to].Z, col.R, col.G, col.B, col.A)
End Sub

[C#]
public void DrawLine(Vector3 from, Vector3 to, Color col)
{
    Function.Call(Hash.DRAW_LINE, from.X, from.Y, from.Z, to.X, to.Y, to.Z, col.R, col.G, col.B, col.A);
}

