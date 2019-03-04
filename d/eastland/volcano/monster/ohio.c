#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(8);
	set_name( "Ohio", "����" );
	set_short( "����" );
	set_long( 
             @LONG
�㿴��������ȥ����ʱ�Ķ�ţ���ͷ�󺹵�����, ������Ҫ��������
LONG
	);
	set( "alignment", 200 );
        set( "gender", "male" );
        set( "race", "human" );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 17 );
	set_perm_stat( "piety", 7 );
	set_perm_stat( "karma", 10 );
	set ("max_hp", 220);
	set ("hit_points", 220);
	set ("wealth", ([ "gold": 5 ]) );
	set("natural_armor_class",30);
	set("natural_defense_bonus",8);
        set_natural_weapon(3,5,5);
    set ("exp_reward",690 );
    set ("chat_chance", 10);
    set ("chat_output", ({
      "����˵������λ�����˿��԰�������\n",
    }) );
}

void init()
{
 add_action( "to_help", "help" );
}

int to_help(string str)
{
   int i;
   object player,ob1,*items;
   if(!str || str != "ohio") {
     write(
           "����˭?\n");
     return 1;
   }
   items=all_inventory(this_player());
   for(i=0;i<sizeof(items);i++)
     if ((string)items[i]->query("name")=="ohio ring")
     {  tell_object(this_player(),
        "����˵�����ҵ��ҵ��ֵ�����\n");
        return 1;
     }
   write( 
     "\n����˵: ���԰��������ҵ��ֵ����������ֵܽ����ɽ����̽�գ�\n" 
     "��;��ĳ�����ϣ�����˯����ͻȻ����һ���ҽУ�����һ�������ֵ���\n"
     "�Ѿ�ʧ���ˡ��ڶ������ϣ���Ҳ�Ͻ���ʰ�������⸽����Ѱ�ҵܵܵ���\n"
     "�䣬������������Ȼ������һ���׶�����ˣ��������ܵÿ죬��Ȼһ��\n"
     "û���ˣ��Ҳ��ҵܴܵ�ű�����ץ���ˣ��ܲ����������������лл��\n"
   );
if ( !this_object()->query_temp("gived") ) {
   write("�뽫�����ָ�����������ͻ�֪���һ�������\n");
   ob1 = new( OOBJ"ohio_ring" );
   ob1->move(this_object());
   set_temp("gived",1);
   command("give ring to "+lower_case((string)this_player()->query("name")));
   this_player()->set_temp("ohio",1);
} else 
	write("��ϧ�Ҹոհ��ҵĽ�ָ����һ��Ը����ҵ��ˣ�������Ϳ��������������ˡ�\n");
   return 1;
}

int accept_item(object me, object item)
{
	string name;
        
        name=(string)item->query("name");
        if ( !name || !(name=="oregon ring")) {
        return 0;
        }

    if (!item->query(me->query("name"))) {
      tell_object(me,
        "����˵���������ָ�Ǵӱ������������İ�!\n");
      return 1;
    }

    tell_object( me, 
      "����˵����! �������ֵܵĽ�ָ��\n"
      "������"+me->query("c_cap_name")+"�ݵ���˵��: лл����ҵ��ֵܳ�����\n"
      "��ҲҪ�����ҵ��ó��ˣ��ټ���\n"
    );
    command("wave "+lower_case((string)this_player()->query("name")));
    if( !me->query_quest_level("Ohio's_brother") ) {
      me->finish_quest("Ohio's_brother",1);
      if ((string)me->query("class")=="scholar") {
        tell_object(me,set_color("�����ִҴ�ææ���ܻ���������������������е�ʱ��õ��ģ����͸���ɣ�˵������\n�������һ�������뿪�ˡ���̯����һ������һ���һ�ľ�У�һ�򿪣�һֻľ�������˳�\n����˵�����ҵ����ˣ���������һЩ����Ȼ�������������㣬����Ҫ���ٻ��ҡ�\n","HIG"));
        me->set("demand/wood",2);
      }
      tell_object( me,
         set_color("[������� Ohio ���񣬵õ� 5000 �㾭��]\n","HIY"));
      me->gain_experience(5000);
    }
    item->remove();
    this_object()->remove();
    return 1;
}
