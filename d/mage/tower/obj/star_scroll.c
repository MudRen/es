//  Created by Yueh in Eastern Story 1995/11/10
#include <mudlib.h>
#include <daemons.h>
#define SLAB_FILE "/d/mage/data/slab.txt"
inherit OBJECT;

void create()
{
	set_name( "white magic scroll", "白色魔法卷轴" );
	add( "id", ({ "scroll" }) );
	set_short( "白色魔法卷轴" );
	set("long","@@desc");
	set( "unit", "张" );
	set( "weight", 5 );
	set( "no_sale", 1 );

}

void init()
{
        add_action( "study_scroll", "study" );
}

int study_scroll(string arg)
{
        object env,me;
	int points,total_points,percentage;
	me=this_player();
        if( !arg || arg!="scroll" )
                return notify_fail("想研究什麽？\n");
        if ((this_player()->query("spell_levels/misc")< 50))
                return notify_fail("这些星空图好像记载了某种法术的秘密，但是你不知道正确的使用方式\n，大概是你对杂项魔法还不够熟练吧！\n");
	points=(int)me->query_explore_points();
	total_points=EXPLORE_D->query_total_explore();
	percentage=points*100/total_points;
	if ( percentage < 60)
return  notify_fail("这些星空图好像记载了某种法术的秘密，你研究了半天，还是不知道这些星空\n图分别是从哪里观察的，大概你的探险度还不够！\n");

if (!undefinedp(this_player()->query("spells/astral-gate")))
return notify_fail("你看看了星空图，对这些星空的分布记得更清楚了。\n");
	write("你开始仔细研究卷轴上的星空图 .... \n\n");
	tell_room( environment(me), sprintf("%s看著卷轴开始发呆。\n", me->query("c_name")), me);
	printf("卷轴发出了白色的光芒，化作了几百颗的白色星星的影像，围绕著你快速的移动著.... \n ...\n ...\n");
	tell_room( environment(me),sprintf("\n%s手上的卷轴发出了白色的光芒，化作了几百颗白色星星的影像，围绕著%s快速的移动.... \n",me->query("c_name"),me->query("c_name")), me);

	call_out("effect",1,me);
        return 1;
}
void effect(object reciter)
{
string fame;
seteuid(getuid());
fame = "     "+(string)reciter->query("c_name")+"("+
                (string)reciter->query("name")+")"+" 於 "+
                "/adm/daemons/weather_d"->query_c_game_time()+" 习得星空之门 !!\n";
                write_file(SLAB_FILE, fame+"\n");
write("从观察星星的分布和移动，你领略出如何使用星空之门！！\n> ");
	tell_room( environment(reciter), sprintf("\n白色星星的影像愈来愈模糊，渐渐的消失不见了.... \n\n> " ));
	this_player()->set("spells/astral-gate",0);
	this_player()->set("spells/star-memory",0);
	remove();
}

string desc()
{
if (undefinedp(this_player()->query("spells/astral-gate")))
return("这张白色卷轴上面画了很多的星空图，想仔细研究(study)这个卷轴(scroll)吗？\n");
else
return("这张白色卷轴上面画著学习星空之门必知的各地星空图。\n");
}

