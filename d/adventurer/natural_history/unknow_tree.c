#include <mudlib.h>
#define FRESH_TIME 600

inherit OBJECT;

void create()
{
	set_name("unknown plant","奇怪的植物");
	add( "id" , ({ "plant" }) );
	set_short("奇怪的植物");
	set_long(
		"这是一株看来颇特殊的植物，但由於附近的植物太茂密，\n"
		"你也不能确定他是不是有用，也许拿把花剪(cut)把它割下来才能\n"
		"搞清楚它是什麽...\n"
	);
   	set("unit","株");
//   	set("cropp",1);
   	set("weight", 10000);
   	set("value",({ 0, "silver" }) );
	set("cropp",1);
	set("is_fresh",1);
}
void init()
{
    add_action("do_cropp","cut");
}    
int do_cropp( string arg )
{
     object obj;
     int i,n;
     string str;      
           
           if ( !arg || arg != "plant") {
           write("你想割什麽??\n");
           return 1;
           }
           if ( !present("scissors",this_player()) ) {
           write("你没有适合的工具喔...\n");
           return 1;
           }
           seteuid(getuid());
           write("你拿起花剪，把这株不明植物割了下来，并且仔细的观察他！\n");
           
           tell_room( environment(this_player()),
           "\n"+this_player()->query("c_name")+"拿出一把锋利的花剪，把路边的一株植物割了下来\n"
           "，并且拿在手上仔细观察...\n\n", ({this_player()}) );
           
           switch( n= random(2) ) {
           case 0: obj = new("/d/noden/farwind/items/branz_herb");break;
           case 1: obj = new("/d/adventurer/natural_history/herb");break;
           default : break;
           }
           
           if (obj->query("c_name")=="布兰兹药草")
           obj->set("need_skill",1);
           
           
           if ((int)obj->query("need_skill") < (int)this_player()->query_skill("natural_history")-1) {              
               
                write("根据你对博物学与自然生物的认识，你断定这是一"+obj->query("unit")+"野生的\n"
                +obj->query("c_name")+"。你很快的把它收起来...\n");      
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"说道: 哈，找到一"+obj->query("unit")+"野生的"
                +obj->query("c_name")+"\n，真是赚到了...\n\n", ({this_player()}) );
                this_player()->gain_experience(5*(int)obj->query("need_skill"));
                obj->move(this_player());
                remove();
                return 1;
                } 
           
           else {
               
                write("你从来没见过这玩意，或许它没什麽用吧..你顺手把它丢在路边\n");
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"似乎不知道采到的植物是什麽，随便把他\n"
                "丢在路边...\n\n",({this_player()}) );
               
                remove();
                return 1;
                }
                }
int move(mixed ob)
{
	if ( ob && living(ob))
        call_out("not_fresh", FRESH_TIME, this_object() );
	return ::move(ob);
}

void not_fresh(object what)
{
	remove();
}
