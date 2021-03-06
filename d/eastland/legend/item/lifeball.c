#include <mudlib.h>
#define MAXHEAL 300
#define NAME(x) (string)x->query("name")
#define LEADER(x) (string)x->query_temp("leader")
#define CNAME(x) (string)x->query("c_name")

inherit OBJECT;

void create()
{
        set_name("life ball", "兜率弥陀珠");
        add("id", ({ "ball" }) );        
        set_short(set_color("兜率弥陀珠","HIY"));
        set_long( @LONG
相传这是紫清玉府太虚宫中，乾灵灯上所结的灯花，被几位谪降的天仙，带临
凡世，仗以御邪防身。先後共七朵，威力大小均不同。那些谪降的仙人大概也
没想到其中一颗乾灵神□居然造就出莽牯朱蛤这毒物。
LONG
        );
        set( "light",3); 
        set( "times_left",5);
        set( "unit", "颗" );
        set( "weight", 10 );
}

void init()
{
  add_action("do_heal_all", "use_lifeball");
}

int who_in_party(object obj, string me)
{
     if( !living(obj) ) return 0;
     if( LEADER(obj)!= me ) return 0;
     return 1;
}

int do_heal_all()
{
    int i, times;
    object *part, me;
    
    me = this_player();
    if (this_object()->query("times_left")<1) {
      tell_object(me,"兜率弥陀珠的光泽慢慢黯了下来并且消失了。\n");
      this_object()->remove();   
      return 1;
    }
    tell_object(me,@LONG

你高捧著兜率弥陀珠对天祈求......

一片五色祥云由远方飘来, 云际金光四射, 罩住了你
LONG); 
    tell_room(environment(me),sprintf(
        "\n一片五色祥云由远方飘来, 云际金光四射, 罩住了%s...\n",me->query("c_name")),me);
    if (!LEADER(me)||LEADER(me)!=NAME(me)) {
      tell_object(me,
        set_color("你觉得神清气爽, 浑身无一处不畅快！\n","HIB"));
      this_player()->receive_healing(MAXHEAL);    
      this_object()->add("times_left",-1);        
      return 1;
    }
    part=filter_array(all_inventory(environment(this_player())),
                       "who_in_party",this_object(),NAME(this_player()));
    i=sizeof(part);
    while(i--) {
      tell_object(part[i],
        set_color("你觉得神清气爽, 浑身无一处不畅快！\n","HIB"));    
      part[i]->receive_healing(MAXHEAL);
    } 
    this_object()->add("times_left",-1);                  
    return 1;
}

