#include "../asterism.h"

inherit OBJECT ;

void create()
{     

        set_name( "bigchest" , "������" ) ;
        add( "id" , ({ "bigchest","chest" })) ;
        set( "unit","��" ) ;
        set_short("һ��������") ;
        set_long(
         @C_TEXT
һ���������������ҵĴ�����,�����е���졣�ô����� ? 
���Ǹ�������ȫ��鶯�� ??
C_TEXT
         );
         
        set("weight", 300 );
        set("prevent_get",1 ) ;
        seteuid(getuid())     ;        
}

void init()
{
     add_action("exam_chest","exam");
     add_action("exam_chest","check");
     add_action("do_hurt","open");
     add_action("do_hurt","search");
     }
     
int exam_chest(string str)
{     
     object mob ;
          
     if (!str || str !="chest") 
         {         
               return notify_fail( "���ʲ�� ?\n" );
         }
     else
      {   
          tell_room(environment(),
           "����������㿿��ʱ,ͻȻ�ſ�Ѫ����,������һ������\n"
            ,this_player() )  ;
          mob = new(MOB"mimic") ;         
          mob->move(environment(this_object())) ;         
          remove() ;
          return 1 ;     
        }            
}              
     
int do_hurt(string str)     
{ 
       object mob ;
       int hp  ;      

       if (!str || str !="chest") 
          {         
           return notify_fail(
                           "������ʲ�� ?\n" );
          }
  
       hp = this_player()->query("hit_points") ;
       
       if (hp <101 )
          {
            this_player()->set("hit_points",1) ;
           }
        else
          { 
            this_player()->set("hit_points",hp-99) ;
           } 
       write(
             "�������ͻȻ�ſ�Ѫ������������һ��ҧ�¡��ۡ�����ʹ��\n"  );
       tell_room(environment(),"�������ͻȻ�ſ���"+this_player()->query("c_cap_name")+
                 "һ��ҧ�¡�\n",this_player() ) ;
          
          mob = new (MOB"mimic") ;
          mob->move(environment(this_object())) ;         
          this_player()->set_explore("noden#34");
          remove() ;
          return 1 ; 
 }
   
