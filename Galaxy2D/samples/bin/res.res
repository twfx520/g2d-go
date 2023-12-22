<Galaxy2D_Game_Engine_Res_File>
    <ResNode ResType="FileTexture">
        <Res ResName="partex" FileName="particle.png" ColorKey="0"/>
    </ResNode>
    <ResNode ResType="EmptyTexture"/>
    <ResNode ResType="TextureSet"/>
    <ResNode ResType="Sound"/>
    <ResNode ResType="Music"/>
    <ResNode ResType="Font"/>
    <ResNode ResType="Image"/>
    <ResNode ResType="Mesh"/>
    <ResNode ResType="String"/>
    <ResNode ResType="Sprite">
        <Res ResName="parspr" TexRes="partex" TexX="0" TexY="0" TexW="32" TexH="32" AlphaAdd="1" ColorAdd="0" HotX="16" HotY="16" XFlip="0" YFlip="0"/>
        <Res ResName="parspr2" TexRes="partex" TexX="32" TexY="0" TexW="32" TexH="32" AlphaAdd="1" ColorAdd="0" HotX="16" HotY="5" XFlip="0" YFlip="0"/>
    </ResNode>
    <ResNode ResType="Animation"/>
    <ResNode ResType="Particle">
        <Res ResName="par" ParName="parspr" MaxCount="500" emitterType="2" emitterDir="2" emitterWidth="50.000000" emitterHeight="50.000000" spinMode="0" emission="185" lifetime="-1.000000" particleLifeMin="0.500000" particleLifeMax="1.500000" direction="1.692969" spread="0.296706" relative="0" speedMin="30.000000" speedMax="80.000000" gravityX="0.000000" gravityY="0.000000" radialAccelMin="0.000000" radialAccelMax="0.000000" tangentialAccelMin="16.000000" tangentialAccelMax="41.000000" sizeStart="1.000000" sizeStartVar="0.000000" sizeEnd="0.600000" sizeEndVar="0.000000" spinStart="0.000000" spinStartVar="0.000000" spinEnd="0.000000" spinEndVar="0.000000" colorStart="14286851" colorEnd="1294848" colorVar="0.070000" alphaVar="0.000000" fadeColorWeight="0.520000" fadeColor="4294304000" fadeColorVar="0.080000" fadeAlphaVar="0.470000"/>
        <Res ResName="par2" ParName="parspr2" MaxCount="500" emitterType="2" emitterDir="1" emitterWidth="270.000000" emitterHeight="270.000000" spinMode="2" emission="80" lifetime="-1.000000" particleLifeMin="0.600000" particleLifeMax="1.400000" direction="0.890118" spread="0.000000" relative="0" speedMin="160.000000" speedMax="180.000000" gravityX="0.000000" gravityY="0.000000" radialAccelMin="80.000000" radialAccelMax="80.000000" tangentialAccelMin="-160.000000" tangentialAccelMax="-160.000000" sizeStart="1.000000" sizeStartVar="0.580000" sizeEnd="1.000000" sizeEndVar="0.550000" spinStart="0.000000" spinStartVar="0.000000" spinEnd="0.000000" spinEndVar="0.000000" colorStart="7676160" colorEnd="16777215" colorVar="0.000000" alphaVar="0.000000" fadeColorWeight="0.440000" fadeColor="1895805743" fadeColorVar="0.070000" fadeAlphaVar="0.080000"/>
    </ResNode>
</Galaxy2D_Game_Engine_Res_File>
