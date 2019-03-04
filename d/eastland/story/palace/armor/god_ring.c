#include <mudlib.h>

inherit ARMOR;

void create()
{
     set_name( "God-Dragon ring","¡õ[1;37mP[0;37m¡õ[1;37ms[0;37m¡õ[1;37m¡õ[0;37m" );
     
     add( "id",({ "ring" }) );
     set_short( "¡õ[1;37mP[0;37m¡õ[1;37ms[0;37m¡õ[1;37m¡õ[0;37m" );
     set_long(@C_LONG
Ò»Ö»Ì«°×½ğ¾«ÖÆ³ÉµÄ½äÖ¸£¬½äÖ¸ÉÏµñ¿ÌÖøÒ»ÌõÒøÁú£¬èòèòÈçÉú£¬»îÍÑ»îÏÖ¡£
C_LONG
     );
     set( "weight",5 );
     set( "unit", "Ö»");
     set( "type", "finger" );
     set( "material","element" );
     set( "defense_bonus",10 );
     set( "value",({ 3000,"silver" }) );
}
