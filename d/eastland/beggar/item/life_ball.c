#include <mudlib.h>

#define COST_HP 60
#define TIME_QUOTA 20
#define INTERVAL 5 
inherit OBJECT;

void create()
{
        set_name( "life ball", "元气玉" );
        add( "id", ({ "ball" }) );
        set_short( "元气玉" );
        set_long(@C_LONG
这是一颗晶萤剔透的生命圆球。元气玉是由『祠堂 老院长』多年研究长生不老之术
小成後的产物。据老院长透露, 你可以把你的生命力贮存( install )在这一颗小小
的圆球里;假以时日,你又可以从圆球中取出( release )生命力;除此之外,你还可以
检查( exam )看圆球是否有生命力,这实在是一件很奇妙的事情。
C_LONG        
        );
        set("unit","个");
        set( "weight", 20 );
        set("no_sale",1);
}

void init()
{
   add_action( "install_ball", "install" );
   add_action( "release_ball", "release" );
   add_action( "exam_ball", "exam" );
}   
   
int install_ball(string arg)
{
   object me,ball;
   int my_hp,my_int,my_ali,times;
   
   if( !arg )
      return notify_fail("你要 install 什麽东西?\n");
         
   me=this_player();
   if( !(ball=present( arg, me )) )
      return notify_fail("你没有这样东西。\n");
   if ( ball->query("name")!="life ball" )
      return notify_fail("Syntax <install ball>\n");
   
   my_ali=me->query("alignment");
   my_int=me->query("spell_points");
   my_hp=me->query("hit_points");      
   times=ball->query("install_times");   
      
               
      if ( ( times > 0 ) && ( ball->query("master") != ( me->query("name")) ) )
          return notify_fail( "\n对不起,这颗元气玉的主人不是你。\n"); 
      
      if ( my_hp < COST_HP ) 
          return notify_fail( "\n因为你太虚弱了而无法把生命力注入圆球里.....\n");    
      
      if ( times > TIME_QUOTA -1  )
          return notify_fail( "\n喔,这颗元气玉已经完全充满了生命力......\n"); 
      
      if ( ball->query("install_wait") )
         return notify_fail( "\n请不要操之过急,请待会儿再注入你的生命力.....\n");
             
      me->add( "hit_points", -COST_HP );
      times=times+1;    
      
      if ( times==1 ) ( ball->set( "master", ( me->query("name")) ) );
      
      ball->set("install_wait",1);    
      ball->set("install_times",times);
      tell_object(me,set_color(
         "\n这颗元气玉一共吸收了你 "+times+" 次的生命力.......\n","HIG"));
      call_out( "install_out", INTERVAL , ball);
   return 1;
}

void install_out(object ball)
{
     tell_object( environment( ball ),set_color(
          "\n元气玉极需要你的生命力.....\n","HIW")); 
     ball->delete("install_wait");   
}

int release_ball(string arg)
{
    object me,ball;
    int times;
    
    if( !arg )
         return notify_fail("你要 release 什麽东西?\n");
    me=this_player();
    if( !(ball=present( arg, me )) )
        return notify_fail("你没有这样东西。\n");
    if ( ball->query("name")!="life ball" )
        return notify_fail("Syntax <release ball>\n");
    times=ball->query("install_times");
      
    if ( times < 1 ) 
       return notify_fail( "\n喔,这颗元气玉毫无生命力可言....\n");               

    if ( ball->query("release_wait") )
       return notify_fail( "\n请待会儿再从元气玉里取出生命力........\n");
    
    if ( ball->query("master") == ( me->query("name")) )
      me->receive_healing( 48 );
    else me->receive_healing( 36 );
    
    times=times-1;
    ball->set("install_times",times);
    tell_object(me,set_color(
       "\n元气玉里头的生命力使你感到一阵温暖,你还发现元气玉留下 "+times+" 次生命力可以取出.....\n","HIC"));
    ball->set("release_wait",1);   
    call_out( "release_out",INTERVAL,ball);
    return 1;
}
void release_out(object ball)
{
     ball->delete("release_wait");
}

int exam_ball(string arg)
{
   object me,ball;
   int times;
   
   if( !arg )
         return notify_fail("你要 exam 什麽东西?\n");
            
   me=this_player();
   if( !(ball=present( arg, me )) )
      return notify_fail("你没有这样东西。\n");
   if ( ball->query("name")!="life ball" )
      return notify_fail("Syntax <exam ball>\n");
   
   times=ball->query("install_times");
   if ( times==0 )
      ball->set("master","???");
      
   tell_object(me,"\n这颗生命圆球的主人是 "+ball->query("master")+
       " 而且已经被注入了 "+times+" 次生命力了......\n");
   
   return 1;
}             