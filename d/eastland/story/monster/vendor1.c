#include "../story.h"
inherit MONSTER;
int left=1;
void create()
{
    ::create();
    set_level(1);
    set_name( "wander merchant", "��������" );
    add("id",({"merchant"}));
    set_short( "��������[����¿����]" );
    set_long(@LONG
����һ���Ĵ����з�����Ʒ���ˣ����������糾���͵����ڸ��������̹���ȥ����
���ľ���һЩϡ��ŹֵĶ��������������ѯ�ʼ۸�(price) �����Ƿ���ʲ�ᶫ��
����ϲ���ġ�
LONG    
    );
    set( "gender", "male" );
    set( "no_attack", 1 );
    set( "inquiry", ([
	 "price" : "@@show_menu",
        "shadow" : "@@ask_shadow" 
    ]) );
    set( "player_invisible" ,1 );
}
void ask_shadow(object asker)
{
  write(@LONG
����˵������Ӵ��ǰ���������и�ðʧ��ײ����һ�£������Բ���û�о��ӵ���
�������������㿴�����Ҷ����ϻ�����һ�飬ʹ���ˣ����Ǹ���ɱ�ģ����������
���������������ˡ��ҿ��������ϱߵ�ɽ�뷽�򣬾�˵���Ǳ������ûһ�߽�����
����������������������������Ҳ�á�  
LONG
  );
}
void show_menu(object asker)
{
 if ( !left ) 
    write("����˵����ร�����Ҫ��������ร��������Ǳ�Ǹ��ȫ���������㣬�����´�������\n");
 else 
    write("����˵������������̫�����ˣ�ֻʣ��ˮ��������(glass)��������Ҫ�𣿻���һ�ţ���Ǯ�� 5000 ���ҡ�\n"); 
}
void init()
{
    ::init();
    add_action("do_buy","buy");
}
int do_buy(string arg)
{
   object glass,player;
   if ( !arg || arg!="glass" )
      return notify_fail("����˵�����ܱ�Ǹ����û������������\n");
   if ( !left )
      return notify_fail("����˵�����Բ��𣬶������ˡ�\n");
   player=this_player();
   if ( !player->debit("silver",5000) ) 
      return notify_fail("����˵�����Բ�����Ǯ������ˮ����������Ҫ 5000 ���ҡ�\n");  
   glass=new(SWITEM"crystal1");
   if( glass->move(player)!=0 ) {
      glass->remove();
      player->add("wealth/silver",5000);
      return notify_fail("�Բ�����������������˵̫���ˡ�\n");
   }                                                                      
   glass->set("special_things",1);
   glass->move(player);
   left=0;
   call_out("back",900);
   return notify_fail("��������������һ��ˮ��������\n");
}
void back()
{  
   left=1; 
}