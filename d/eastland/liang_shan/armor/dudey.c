#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("License of monks","度牒");
        add("id",({"license"}) );
         set_short( "a license of monks","度牒");
	set_long(
"度牒是各寺庙在僧侣剃度时，发给的身份证明，通常都经过高僧的祝福．\n"
"能坚定僧侣向佛之心．\n"
);
	set( "unit", "本" );
	set( "weight", 30 );
	set( "type", "misc" );
	set( "material","monk");
	set( "defense_bonus", 6 );
	set( "no_sale",1);
	set( "value", ({ 250, "gold" }) );
        set( "extra_skills",(["inner-force":8]));
        set( "special_defense",(["evil":30 ,"divine":5]));
}
