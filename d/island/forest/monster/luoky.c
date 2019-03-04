#include "../tsunami.h"
#include "/include/move.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(10);
    set_name( "luoky", "�˻ʹ�" );
    add( "id",({"luoky"}) );
    set_short( "�˻ʹ�" );
    set_long(@LONG
����һֻ���������ӣ�����ȴ��è��С����ܿɰ��ɣ�������ɰɴ��������
�����أ���ǧ��Ҫ�۸���Ŷ�������������Ǵ��Ŷ�������ι���ܲ�(radish)
�Ļ������ͻ�����׽�Ŷ��
LONG
            );
    set("aligment",1000);
    set_c_verbs( ({"%s��������������ҧ��%s","%sǿ����������������%s",
                   "%s�������Ķ���˦��%s"}) );
    set_perm_stat( "str", 10);
    set_perm_stat( "dex", 10);
    set_perm_stat( "int", 15);
    set( "chat_chance",5);
    set( "chat_output", ({
  "�˻ʹ��ñ��ӱ��ű߽���: ������������Ҫ�ܲ���������������������\n"
       }));
    set("hit_points",200);
    set("max_hp",200);
    set_natural_weapon( 30, 15, 30 );
    set_natural_armor(35,10);
    set("c_death_msg","���������һ�²���̫���ˣ�%s����Ѫ������������ǣ�\n");
}

int accept_item(object player,object obj)
{ 
   object *item, ob1, ob2;
   int i;
   ob1 = ( present("luoky")); 
   ob2 = new(TOBJ"crystal");
   
   if(!obj || !(obj->query("give_me_radish")) ) {
   tell_room(environment(),
   "�˻ʹ�����������װ�������޵��������������������ܲ��ܲ�����\n");
   return 1;
   }
   
   if( (string)obj->query("owner") != (string)player->query("name") ){
   tell_object(player,"�˻ʹ�޵�����������û�г���������Ȼ����һֻ�����ʵ��ܲ�����������\n");
   obj->remove();
   return 1;
   }
   
   tell_room(environment(),
     "�˻ʹ������ҧ���ܲ������һ��ˮ����Χ����"+player->query("c_name")+
     "����........\n");
   tell_object(player,"�˻ʹ����˵��������һ��ҵ������Ƕ�ȥ!!\n");
   ob2->set("winner",(string)player->query("name"));
   ob2->move(player);
   item = all_inventory(ob1);
   for( i=0; i<sizeof(item); i++ ) item[i]->remove();
   ob1->remove();
   return 1;
} 

void die()
{
   object killer;
   killer = query( "last_attacker" );
   
   if( !killer ){
   ::die();
   return;
   }
   killer->set_temp("luoky_killer",1);
   ::die();
}   
            
