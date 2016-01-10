#include <metal_stdlib>

using namespace metal;

struct Uniforms
{
    float4x4 rotation_matrix;
};

struct VertexIn
{
    float4 position;
    float4 color;
};

struct VertexOut
{
    float4 position [[position]];
    float4 color;
};

vertex VertexOut vertex_function(device VertexIn *vertices [[buffer(0)]],
        constant Uniforms &uniforms [[buffer(1)]],
        uint vid [[vertex_id]])
{
    VertexOut out;
    out.position = uniforms.rotation_matrix * vertices[vid].position;
    out.color = vertices[vid].color;
    return out;
}

fragment float4 fragment_function(VertexOut in [[stage_in]])
{
    return in.color;
}
