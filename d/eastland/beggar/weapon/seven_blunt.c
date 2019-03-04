#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("seven blunt","七宝金幢");
        add("id",({"blunt",}) );
       set_short("七宝金幢");
       set_long(@C_LONG
七宝金幢传说是降魔伏妖的稀世宝物。此物原来是放在七七四十九重天,用来镇住
伏妖塔的咒物,但是,千百年前的一场神魔大战而失落人间。因此,也让被锁在伏妖
塔里的一百零八魔乘机跑了出来为害人间。传说中,七宝金幢还有另一项用法, 那
就是...........『三十六记走为上策』,但时日已久不知道是否飞得动? 
C_LONG
               );
	set( "unit", "把" );
 	setup_weapon("blunt",30,10,25);
	set( "weight", 80 );
	set( "value", ({ 240, "gold" }) );
        set_c_verbs( ({ 
           "张开手里的%s变成一件斗大的兵器向著%s的要害打去",
           "双手高高地举起%s,斜斜地砍向%s",
           "手持%s一招看似极为笨拙的棍法对著%s打去",
           "把%s插在背後的裤带揉身而上向%s扑去"
        }) );
}
void init()
{
   add_action("do_fly","fly");
}
int do_fly(string arg)
{
   object me,*usr,target,env;
   string *envname ;
   
   if ( !living(environment(this_object())) ) {
      tell_object(this_player(),
        "你一直对著地上的七宝金幢喊『飞』,但它一动也不动地似乎不想理你～～\n");
      tell_room(environment(this_object()),this_player()->query("c_name")+
        "暴跳如雷地对著地上的七宝金幢喊『飞』,但七宝金幢似乎理也不理～～\n",
        this_player() );
      return 1;  
   }
   usr=users();
   me=this_player();
   target = usr[ random( sizeof(usr)-1 )];
   env = environment(target) ;
   
   if ( me->query("hit_points") < 120 ) {
      tell_object(me,"呜,你太虚弱了～～\n");
      return 1;
   }
   if(!env) {
      tell_object(me,"再试一次～～\n");
      return 1 ;
   }  
   envname = explode(base_name(env),"/") ;
                
   if((envname[0] != "d")|| !environment(target)->query("outside")) {
     tell_object(me,"再试一次～～\n"); 
     return 1 ;
   }
   if( wizardp(target) || target == me ) {
     tell_object(me,"再试一次～～\n");
     return 1;
   }
   me->set("hit_points",30);
   tell_object(me,
      "你打开七宝金幢的伞翼,咻～～\n\n");  
   tell_room(environment(me),me->query("c_name")+
      "打开七宝金幢的伞翼,咻～～整个人就不见了～～\n\n",me);
   me->move_player(environment(target),"SNEAK");
   tell_object(me,
      "咻～～你乘著七宝金幢飞到了一个奇怪的地方.......这是那里啊?\n\n");
   tell_room(environment(target),
      "咻～～～～某个东西摔在你身旁\n\n",me);
   return 1;   
}
