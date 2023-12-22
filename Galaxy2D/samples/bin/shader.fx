sampler2D uSourcImg;

float4 main(float2 vTexCoord:TEXCOORD0) : COLOR0 
{  
	float2 pixelSize = float2(1.0 / 640, 1.0 / 480);
	float4 sum = float4(0, 0, 0, 1); 
	
	sum += tex2D(uSourcImg, float2(vTexCoord.x - 4.0 * pixelSize.x, vTexCoord.y - 4.0 * pixelSize.y)) * 1.0 / 47.0;  
    sum += tex2D(uSourcImg, float2(vTexCoord.x - 3.0 * pixelSize.x, vTexCoord.y - 3.0 * pixelSize.y)) * 2.0 / 47.0;  
    sum += tex2D(uSourcImg, float2(vTexCoord.x - 2.0 * pixelSize.x, vTexCoord.y - 2.0 * pixelSize.y)) * 3.0 / 47.0;  
    sum += tex2D(uSourcImg, float2(vTexCoord.x - pixelSize.x, vTexCoord.y - pixelSize.y)) * 10.0 / 47.0;  
    sum += tex2D(uSourcImg, float2(vTexCoord.x, vTexCoord.y)) * 15.0 / 47.0;  
    sum += tex2D(uSourcImg, float2(vTexCoord.x + pixelSize.x, vTexCoord.y + pixelSize.y)) * 10.0 / 47.0;  
    sum += tex2D(uSourcImg, float2(vTexCoord.x + 2.0 * pixelSize.x, vTexCoord.y + 2.0 * pixelSize.y)) * 3.0 / 47.0;  
    sum += tex2D(uSourcImg, float2(vTexCoord.x + 3.0 * pixelSize.x, vTexCoord.y + 3.0 * pixelSize.y)) * 2.0 / 47.0;  
    sum += tex2D(uSourcImg, float2(vTexCoord.x + 4.0 * pixelSize.x, vTexCoord.y + 4.0 * pixelSize.y)) * 1.0 / 47.0;  
	
	return sum;  
}  