#include <mudlib.h>

#define COST_HP 60
#define TIME_QUOTA 20
#define INTERVAL 5 
inherit OBJECT;

void create()
{
        set_name( "life ball", "Ԫ����" );
        add( "id", ({ "ball" }) );
        set_short( "Ԫ����" );
        set_long(@C_LONG
����һ�ž�ө��͸������Բ��Ԫ�������ɡ����� ��Ժ���������о���������֮��
С����Ĳ������Ժ��͸¶, ����԰��������������( install )����һ��СС
��Բ����;����ʱ��,���ֿ��Դ�Բ����ȡ��( release )������;����֮��,�㻹����
���( exam )��Բ���Ƿ���������,��ʵ����һ������������顣
C_LONG        
        );
        set("unit","��");
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
      return notify_fail("��Ҫ install ʲ�ᶫ��?\n");
         
   me=this_player();
   if( !(ball=present( arg, me )) )
      return notify_fail("��û������������\n");
   if ( ball->query("name")!="life ball" )
      return notify_fail("Syntax <install ball>\n");
   
   my_ali=me->query("alignment");
   my_int=me->query("spell_points");
   my_hp=me->query("hit_points");      
   times=ball->query("install_times");   
      
               
      if ( ( times > 0 ) && ( ball->query("master") != ( me->query("name")) ) )
          return notify_fail( "\n�Բ���,���Ԫ��������˲����㡣\n"); 
      
      if ( my_hp < COST_HP ) 
          return notify_fail( "\n��Ϊ��̫�����˶��޷���������ע��Բ����.....\n");    
      
      if ( times > TIME_QUOTA -1  )
          return notify_fail( "\n�,���Ԫ�����Ѿ���ȫ������������......\n"); 
      
      if ( ball->query("install_wait") )
         return notify_fail( "\n�벻Ҫ��֮����,��������ע�����������.....\n");
             
      me->add( "hit_points", -COST_HP );
      times=times+1;    
      
      if ( times==1 ) ( ball->set( "master", ( me->query("name")) ) );
      
      ball->set("install_wait",1);    
      ball->set("install_times",times);
      tell_object(me,set_color(
         "\n���Ԫ����һ���������� "+times+" �ε�������.......\n","HIG"));
      call_out( "install_out", INTERVAL , ball);
   return 1;
}

void install_out(object ball)
{
     tell_object( environment( ball ),set_color(
          "\nԪ������Ҫ���������.....\n","HIW")); 
     ball->delete("install_wait");   
}

int release_ball(string arg)
{
    object me,ball;
    int times;
    
    if( !arg )
         return notify_fail("��Ҫ release ʲ�ᶫ��?\n");
    me=this_player();
    if( !(ball=present( arg, me )) )
        return notify_fail("��û������������\n");
    if ( ball->query("name")!="life ball" )
        return notify_fail("Syntax <release ball>\n");
    times=ball->query("install_times");
      
    if ( times < 1 ) 
       return notify_fail( "\n�,���Ԫ�����������������....\n");               

    if ( ball->query("release_wait") )
       return notify_fail( "\n�������ٴ�Ԫ������ȡ��������........\n");
    
    if ( ball->query("master") == ( me->query("name")) )
      me->receive_healing( 48 );
    else me->receive_healing( 36 );
    
    times=times-1;
    ball->set("install_times",times);
    tell_object(me,set_color(
       "\nԪ������ͷ��������ʹ��е�һ����ů,�㻹����Ԫ�������� "+times+" ������������ȡ��.....\n","HIC"));
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
         return notify_fail("��Ҫ exam ʲ�ᶫ��?\n");
            
   me=this_player();
   if( !(ball=present( arg, me )) )
      return notify_fail("��û������������\n");
   if ( ball->query("name")!="life ball" )
      return notify_fail("Syntax <exam ball>\n");
   
   times=ball->query("install_times");
   if ( times==0 )
      ball->set("master","???");
      
   tell_object(me,"\n�������Բ��������� "+ball->query("master")+
       " �����Ѿ���ע���� "+times+" ����������......\n");
   
   return 1;
}             