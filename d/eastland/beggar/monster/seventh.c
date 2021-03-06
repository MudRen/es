#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "seven-bag beggar", "七袋弟子" );
	add( "id",({"beggar","seven"}) );
	set_short( "丐帮 七袋弟子" );
	set_long(@C_LONG
丐帮七袋弟子在帮中地位算是蛮高, 他现在正在教导五袋弟子的武功。 
C_LONG	
        );
        set( "unit", "名" );
	set_perm_stat( "str", 22 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 20 );
        set("weight",650);
	set_skill( "dodge", 80 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "race","human");
	set( "gender", "male" );
	set( "alignment", 200 );
	set_natural_armor( 25, 10 );
	set_natural_weapon( 40, 18, 20 );
        set( "natural_weapon_class2", 40 );
        set( "natural_min_damage2", 15 );
        set( "natural_max_damage2", 25 );
	set( "wealth/gold", 60 );
        set("chat_chance",15);
        set("chat_output",({
          "七袋弟子说道：不对不对,怎麽教几次还不懂啊?\n",
          "七袋弟子说道：你又搅错了,不是这样啊!!\n"                        
                                  }) );
	set_c_verbs( ({ "%s踏步向前，一记直拳打向%s",
		"%s一记 『太祖长拳』，双拳直取%s",
		"%s一招  『声东击西』，右足点向%s", 
		"%s一招 『猛虎出闸』，左拳如风，直取%s",
                   }) );

}
