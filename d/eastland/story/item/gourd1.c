#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("red gourd","大红葫芦");
        add("id",({"gourd"}));
        set_short( "@@query_short");
        set_long("@@query_long");
        set("unit","个");
        set("weight",10);
        set("no_sale",1);
        set("value", ({100, "silver"}) );
}
string query_short()
{
   return sprintf("大红葫芦%s", (query("heaven_water") ? " (装著天堂之水)" : "") );
}
string query_long()
{
   return sprintf("一个红色的大葫芦，%s", (query("heaven_water") ? "可以把里面的溶液倒出来(full)。\n":"可以用来当容器(fill)用。\n"));
}
void init()
{
   add_action("do_full","full");
   add_action("do_fill","fill");
}
int do_full(string arg)
{
   object player,flute;
   if ( !query("heaven_water") ) 
      return notify_fail("葫芦里没有任何溶液。\n");
   if ( !arg ) return notify_fail("Syntax:<full items>。\n");
   player=this_player();
   if ( !(flute=present(arg,player)) )
      return notify_fail("你没有那样东西。\n");
   if ( flute->query("name") != "fly flute" )
      return notify_fail("你不能把葫芦里的「天堂之水」倒进那里面去！\n");
   if ( flute->query("left_times") )
      return notify_fail("那东西里面已经充满著「天堂之水」了。\n");
   write("你缓缓地把葫芦里的「天堂之水」倒进「飞翔之笛」内。\n");
   flute->set("flute_left",1);
   remove();        
   return 1;
}
int do_fill(string arg)
{
   object env;
   if( !arg || arg!="gourd" )
      return notify_fail("Syntax:<fill gourd>。\n");
   if( query("heaven_water") )
      return notify_fail("葫芦内已经装满溶液了。\n");
   env=environment(this_object());
   if( living(env) ) env = environment(env);
   if( !env->query("heaven_water") )
      return notify_fail("这个葫芦不是用来装这里的任何溶液！\n");
   set("heaven_water",1);
   write("\n\n忽然从葫芦口产生一股力量把这里的气体吸进去，瞬间，气体变成了圣水－「天堂之水」。\n\n\n");
   return 1;    
}