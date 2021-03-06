#include "../island.h"

inherit OBJECT;
int announce(object ppl);

void create()
{
	seteuid( getuid() );
	set_name( "peace stone", "和平纪念碑" );
	add( "id", ({ "stone" }) );
	set_short( "和平纪念碑" );
	set_long(@LONG
象徵和平的纪念碑，不过倒置的武器造型，让你觉的相当有趣！
LONG
	);
	set( "unit", "座" );
	set( "prevent_get",1 );
}

void init()
{ 
	add_action( "do_beg", "beg" ); 
}

int do_beg(string arg)
{
	object obj,obj1,env,player;
	string pname;

	env=environment(this_object());
	player=this_player();
	pname=player->query( "c_name" );

	if( !arg )
		return notify_fail( "你想做什麽！？\n" );

	if( arg != "Lizardman Holy Knight" )
		return notify_fail( "求谁啊？\n" );

	if( (int)player->query_level()<=5 )
		return notify_fail( "小小年纪，不要学做坏事！\n" );

	if( !(obj=present("lizardman holy knight",env)) )
		return notify_fail("你想求的人不在这儿啊！\n");

	if( (int)player->query_temp("jousting")==1 ) {
		if( (int)(obj->query("no_jousting"))==0 ) {
			obj1=new( IWEP"jousting" );
			obj1->move( player );
			obj->set("no_jousting",1);
			write("\n圣骑士将石碑拔起交给了你，咦？竟变成『创世神戟』了！\n\n");
			tell_room(env,set_color("\n你看到圣骑士伸出双手用力地握住石碑，石碑的外壳立刻化为碎片；\n就在石碑碎掉的同时，一道耀眼的光芒由圣骑士手上发出，令你几乎张不开眼睛。\n你好奇的往圣骑士双手看去。咦，那不就是传说中的『创世神戟』吗？\n接著圣骑士便把戟交给了"+pname+"\n","HIY"),player );
		}
		else {
			player->set_temp("jousting",0);
			player->set_temp("holy_knight",0);
			write("\n圣骑士对你说：『抱歉，神戟早被取走了。』\n\n" );
		}
	}
	player->set_temp("jousting",0);
	player->set_temp("holy_knight",0);
	player->set( "talk_points",50 );
	announce(player);
	tell_room( environment(player),set_color(
	"\n圣骑士举起手掌，轻轻在石碑上一拍，石碑就灰飞湮灭了。\n","HIR" ) );
	obj->leave();
	call_out("s_war",2);
	return 1;
}

void s_war()
{
	find_object_or_load(IWAR"islandwar")->start_war();
	remove();
}

int announce(object ppl)
{
	string class1,cname,name,cclass;
	object *usr;
	int i;

	usr=users();
	cname=ppl->query("c_name");
	name=ppl->query("name");
	class1=ppl->query("class");
	if (class1=="knight") { cclass="「骑士」";}
	else if (class1=="healer") { cclass="「行医者」";}
	else if (class1=="scholar") { cclass="「书生」";}
	else if (class1=="monk") { cclass="「武僧」";}
	else if (class1=="mage") { cclass="「魔法师」";}
	else if (class1=="thief") { cclass="「小偷」";}
	else { cclass="某个";}

	for(i=sizeof(usr)-1;i>=0;i--) {
	tell_object(usr[i],set_color("远方传来"+cname+"("+name+")的呐喊 :","HIR")+"我要发动摘仙岛战争了，为了 "+set_color(cclass,"HIW")+" 的名誉\n我总有一天会清完的，呵呵.....\n*"+cname+"对你露出神秘的笑容*\n");
	}
	return 1;
}
