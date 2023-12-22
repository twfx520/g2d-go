#pragma once

namespace gge
{
	static ggeAnimation* CreateAnimationSprite(ggeTexture *tex, int frames, float width, float height, bool bCenter = true)
	{
		ggeAnimation *ani = Animation_Create();
		ani->SetSpeed(5);
		if (ani)
		{
			float tx = 0;
			float ty = 0;
			for (int i = 0; i < frames; i++)
			{
				ggeSprite *spr = Sprite_Create(tex, tx, ty, width, height);
				if (bCenter)
					spr->SetHotSpot(width / 2.0f, height / 2.0f);
				ani->AddFrameSprite(spr);
				GGE_RELEASE(spr);

				tx += width;
				if (tx + width > tex->GetWidth(true))
				{
					tx = 0;
					ty += height;
				}
			}
		}

		return ani;
	}
}