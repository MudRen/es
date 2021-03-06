#include <mudlib.h>
inherit OBJECT;
int weted;

string query_c_long()
{
   if ( weted )
  	return  "这个沾了水的石头似乎快要溶掉了，若不赶快把它弄乾(dry)，\n"
        	"你可得准备回去挨老婆的一顿臭骂或只得将衣服丢掉!!。\n";
	else
	return  "这个黑色石头看来脏脏的、软软的，跟一般石头不太一样，上面\n"
		"似乎写著三个字 w?t，中间的字被一个大 Ｘ 给盖住而看不清楚。\n";
}

void create()
{
	set_name("black stone", "黑色石头");
	add( "id", ({ "blackstone","stone" }) );
	set_short( "黑色石头" );
	set("long","@@query_c_long");
	set( "weight", 3 );
	weted = 0;
}

int query_weted() { return weted; }

void init()
{
	add_action( "wet_stone", "wet" );
	add_action( "dry_stone", "dry" );
	add_action( "apply_wall", "apply" );
}

int wet_stone(string arg)
{
   object env;

   if( !arg || arg!="blackstone" && arg != "stone" )
     return notify_fail("将什麽弄湿？\n");
   if ( weted )
     return notify_fail("黑色石头已经弄湿了,似乎用来用来涂墨(apply)!!。\n");

	env = environment(this_object());
	if( living(env) ) env = environment(env);
	if( !env->query("water_source") )
		return notify_fail("这里没有水....。\n");

	weted = 1;
	write("你把黑色石头弄湿，似乎可以用来涂墨(apply)!!。\n");
	call_out("mess_up", 200);
	return 1;
}

int dry_stone(string arg)
{
        if( !arg || arg!="blackstone" && arg != "stone" )
		return notify_fail("弄乾什麽？\n");
	if( !weted )
		return notify_fail("手痒吗? 黑色石头已经是乾的呀!!。\n");
	weted = 0;
	write("你张开大口用千年薰人的功力把黑色石头弄乾了。\n");
	return 1;
}

void mess_up()
{
	object owner;
        if (!weted) return ; 
	owner = environment(this_object());
	if( living(owner) ) {
	tell_object(owner, "黑色石头已经弄脏了你的衣服，回去可得挨骂，你只得随手将它扔了。\n");
	}
	remove();
	return;
}

int apply_wall(string str)
{
        object obj1, obj2;
   if (!weted) {
     write("你不禁敲敲自己的脑袋说：秀逗啦，没水怎麽涂墨呢？\n") ;
     return 1;
   } else {
        if ( !str || str=="" || str !="wall" )
          write("你把自己弄的一身脏兮兮的，这样可追不到帅哥或美女喔 !!\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if ((int)obj2->query("apply")==1) 
              obj2->to_find_wall(str);
            else
              write("这里不能随便涂墨，当心被抓到打屁股！\n");
          }
          else return notify_fail("你手上并没有工具。\n");  
        }
        return 1;
  }
}
