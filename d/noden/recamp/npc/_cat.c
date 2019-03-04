#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;
	ob->set_level(3);
	ob->set_name( "big cat", "大懒猫" );
	ob->add( "id", ({ "cat","big cat" }) );
	ob->set_short( "大懒猫" );
	ob->set_long(
	 "你看到一只巨大的懒猫，正躲在角落。\n"
	);
	ob->set( "unit", "只" );
	ob->set( "alignment", -200 );
	ob->set_c_verbs( ({ "%s张开大嘴往%s腿上一咬" }) );
	ob->set_c_limbs( ({ "头部", "身体", "腿部" }) );
        ob->set("chat_chance",5) ;
        ob->set("att_chat_output",
          ({"大懒猫说:命苦呀! 抓不到老鼠还不够? 大侠你还要我的命!!\n",
            "大懒猫说:大侠别杀我!! 我知道角落藏著的秘密 !!\n",
            "大懒猫说:死老鼠! 别偷笑! 待会而就换你遭殃啦!!\n"})) ;
}
