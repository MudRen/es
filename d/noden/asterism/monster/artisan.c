#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "Artisan Leo", "半身人工匠李欧" );
	add("id",({"artisan","halfling","leo"}) );
	set_short( "半身人工匠李欧" );
	set_long(
		"一个正在修理(fix)魔法物品的矮人工匠。\n"
	);
	set( "gender", "male" );
	set( "race", "halfling" );
	set( "alignment", 600 );
	set( "time_to_heal", 8 );
        set("max_hp",500);
        set("hit_points",500);
	set_natural_armor( 80, 39 );
	set_natural_weapon( 60 , 30 , 48 );
	set_perm_stat( "str", 27 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "con", 35 ); 
        set_perm_stat( "kar", 30 );
        set("special_defense",(["all":40,"none":0]));
        set("aim_difficulty",(["critical":30,"weakest":30,
                               "vascular":30,"ganglion":30 ])) ;

        set_skill("dodge",65)    ;
        set_skill("unarmed",100) ;
	set( "wealth/gold", 100 );
	set( "inquiry" , ([ "fix":"@@fixing",]) ) ;

}

void init()
{
  add_action("fix_item","fix") ;
}

void fixing(object who)
{
  tell_object(who,"李欧说:是的，只要是本城的产品，我应该会修。\n") ;
}

int fix_item(string s)
{
     if( !s || s!="wand" )
        return notify_fail("李欧说: 修理什麽东西 ? 修理你吗 ??\n" );
     write("修理费要三百个金币,要修就把东西给我吧 !!\n" );
     return 1;
}

int accept_item(object me,object item)
{
	string name ;
	name = (string)item->query("name");
	if ( name != "Wand of Ultimate" ) {
		tell_object(me,"李欧摇摇头 : 我不修理这种东西。\n");
		command("give "+name+" to "+(string)me->query("name"));
		return 1;
	} else
	if (!item->query("damaged"))	{
		tell_object(me,"李欧摇摇头 : 这把杖并没有坏。李欧把永恒之杖还给你。\n");
		item->move(me);
		return 1;
	} else
	if ((int)me->query("wealth/gold")< 300)	{
		tell_object(me,"李欧摇摇头 : 你的钱不够。李欧把永恒之杖还给你。\n");
		item->move(me);
		return 1;
	} else {
	tell_object(me,"李欧转过头，开始努力工作 !!\n");
	call_out("do_fix",4,me,item);
	return 1;
	}
}

int do_fix(object me,object wand)
{         
          me->add("wealth/gold",-300) ;                
          wand->set("short","永恒之杖") ;
          wand->set("weapon_class",40) ;
          wand->set("damaged",0) ;
          wand->set("min_damage",24);
          wand->set("max_damage",37);             
          write("李欧说: 修好了，这麽好的武器别再弄坏了。\n" );
		  command("give wand to "+(string)me->query("name"));
          return 1 ;
}


