#include <uid.h>
#include <mudlib.h>
#include <daemons.h>

#define CAMP_FILE "/open/camp/"+(string)this_player()->query("name")+"_incamp.c"
#define SOURCE_FILE "/d/adventurer/hall/incamp.c"

inherit REF_D;
inherit DAEMON ;
inherit OBJECT;

void create()
{
	seteuid(getuid());
        set_name( "camp tools","露营工具包" );
	add( "id",({"camp","tool","camp tool"}) );
	set_short(set_color("露营工具包","HIB"));
	set_long("这是一个装满营钉，营帐，防水布，睡垫等工具的小包包。\n"
                 "你可以使用它在野外建造(build)一个温暖的小帐篷。\n");
	set("unit","个");
	set("no_sale",1);
	set("weight",300);
        set("value",({ 3000,"silver" }));
        set("size",1);
        set("prevent_drop",1) ;
}

void init()
{
	add_action("help_camp","help");
	add_action("cmd_build","build");
        add_action("cmd_setsize","setsize");
}
int copy_file(string from, string to) {
    string str;
            str = read_file(from);
            if (file_exists(to))  rm(to);
            write_file(to,str);
            return 1;
}
void do_camp(object me, int skill, int size )
{ 
   object camp;
   string b_name,e_name;

   camp = new("/obj/camp");
   camp->move(environment(me));
   camp->set("size",size);
   camp->set("skill",skill);
   camp->set("last_locate",environment(me));
   b_name = me->query("c_name");
   e_name = me->query("name");   
   camp->set("creater",b_name);
   camp->set("creater_name",e_name);
   if (file_exists(CAMP_FILE)) rm(CAMP_FILE);
   write_file(CAMP_FILE,"inherit \""+SOURCE_FILE+"\";");
//   cp(SOURCE_FILE,CAMP_FILE);
   camp->set("TO_WHERE",CAMP_FILE);
   me->delete_temp("block_command");
   this_object()->remove();
   return;
}

int cmd_setsize(string size)
{
    if(!size)
        return notify_fail("现在的营帐大小设定在 "+ this_player()->query("camp_size") +"
人帐。\n用法请详见 help camp。\n") ;
    switch(size)
       {
          case "1" : this_player()->set("camp_size", 1 ) ;
                     write("现在的营帐大小设定在 "+ size +"人帐 。\n") ;
                     break ;
          case "2" : this_player()->set("camp_size", 2 ) ;
                     write("现在的营帐大小设定在 "+ size +"人帐 。\n") ;
                     break ;
          case "3" : this_player()->set("camp_size", 3 ) ;
                     write("现在的营帐大小设定在 "+ size +"人帐 。\n") ;
                     break ;
          case "4" : this_player()->set("camp_size", 4 ) ;
                     write("现在的营帐大小设定在 "+ size +"人帐 。\n") ;
                     break ;
          case "5" : this_player()->set("camp_size", 5 ) ;
                     write("现在的营帐大小设定在 "+ size +"人帐 。\n") ;
                     break ;
          case "6" : this_player()->set("camp_size", 6 ) ;
                     write("现在的营帐大小设定在 "+ size +"人帐 。\n") ;
                     break ;

          default  : write("用法请详见 help camp。\n") ;
                     break ;
        }
    return 1;
}
int cmd_build(string str)
{
    int skill, hp, alignment,time, size;
    object me,env;
	
    me = this_player();
    env = environment(me) ;
    skill = (int)me->query_skill("camp");
    size = this_player()->query("camp_size");
    time =  6 + size*2 - skill/10 ;
     
    if (!str || str!="camp") return 0 ;
    if( !skill ) return notify_fail("你没有学过扎营，所以无法搭起帐蓬..。\n");
    if( skill < size*10 ) return
notify_fail("你的扎营技巧不足以搭起这麽大的帐蓬 。\n");
    if( (int)me->query_attacker()) {
      write("在战斗中扎营，想要找老黑泡茶吗？\n");
      tell_room( env, me->query("c_name") + "想在战斗中扎营，难道他想找老黑泡茶吗？\n",me) ;
      return 1;
    }
    if( !environment(me)->query("outside") )
            return notify_fail("这里的地面太硬，不适合搭帐棚。\n");
    if( env->query( "underwater" ) )
            return notify_fail("在水中搭帐棚不是个好主意。\n");
    if( env->query( "flamezone" ) )
            return notify_fail("这里好热喔，搭了可能帐棚会烧掉。\n");        
    if( env->query_temp( "adv_camp" ) )
	return notify_fail("这里已经有别人先搭帐棚了。\n");
    write("你卷起衣袖，把帐棚工具拿出来，用最快的速度开始搭帐棚。\n");
    		
    tell_room( env, 
	me->query("c_name")+"卷起衣袖，把帐棚工具拿出来，用最快的速度开始搭帐棚。\n",
		me );

    env->set_temp("adv_camp", 1);
    if( !wizardp( me ) ) {
	me->set_temp("block_command", 1 );
    }		
    call_out( "do_camp", time , me, skill, size );
    return 1;
}


int help_camp(string str)
{
    if (!str || ( str!="camp" && str!="build" ) ) return 0 ;
    write(@HELP
Syntax: build camp 

当你使用 build 这个指令，如果你所在的地方合适的话，你会
在你所在的房间中造出一间帐蓬，一间房间只能建一间帐蓬，在帐
蓬中睡眠或休息将会加快你生命点数，精神力，以及谈话点数恢复
的速度，但若在睡眠时遭受攻击，很可能就会因此一睡不醒。
你也可以使用setsize 这个指令设定帐蓬供多少人使用，通常建越
大的帐蓬能容纳越多的人，休息的效果更好，但需要越久的时间与
越高的技术来建造它。
搭好的帐蓬可能被风给吹坏，所以当你不用时，马上拆(destroy)
掉它是比较好的作法。
HELP
	);
    return 1;
}
