#include "../dony.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "Sleeping man", "��˯��·�ߵ���" );
    add( "id",({"man"}) );
    set_short( "��˯��·�ߵ���");
    set("no_attack",1);
    set_long(@C_LONG
һ������Ƶ���·�ߵ��ˡ�������Ƴ�ζ,����ȫ����Ż,�������ƺ�֪��
ĳЩ����,������˵��������¶ʲ��Ӵ!!!
C_LONG
            );
    set("unit","λ");
    set("race","human");      
    set("age",18);
    set("gender","man" );
    set("alignment",1000);
    set("weight",300);
    set("hit_points",1);
    set("max_hp",1);
}        

void init()
{ add_action("do_slap","slap");}

int do_slap(string arg)
{
   object ob1;
     
   if ( arg=="man" ){ 
     if (this_player()->query_temp("button")){
        tell_object(this_player(),
"��˵��:�����,��ʲ�ᳳ,�ٳ��Ҵ���ม�\n");
     }
     else {                                                            
       tell_object(this_player(),
"\n     ��Ӵ,Ϻ�״��־��,�˼�˯�úúõ�!!˵����������˯,����\n"
"����������,˵��:Ŷ,ԭ�����Ҽ���֧ĸ�ϻ����������,��ȥ�ɡ�\n\n"
       );
       ob1 = new(DITEM"button");
       ob1->move(this_object());
       this_player()->set_temp("button",1);
       command("give "+(string)ob1->query("name")+" to "+
       lower_case((string)this_player()->query("name")));
     } 
   }
     return 1;
}