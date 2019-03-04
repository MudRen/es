#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(16);
	set_name( "Dwarf Queen Lilies", "���˻ʺ�����˿" );
	add ("id", ({ "queen", "lilies", "dwarf", }) );
	set_short( "Dwarf Queen Lilies", "���˻ʺ�����˿" );
	set_long(
    "a sad queen.\n",@DESC
һ�����˵Ļʺ�,�Դ����Ĵ��������֮��,������Ҳû��Ц����.
���ƺ���Ҫ���˵İ�ο(comfort).
DESC
	);

    set( "gender", "female" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 21 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 20);
	set ("max_hp", 999);
	set ("hit_points", 999);
	set ("wealth", ([ "gold": 50 ]) );
	set_natural_weapon(35,20,45);
	set_natural_armor(80,22);
	set ("special_defense",(["all":33]));
    set ("weight", 300);
    set_skill("dodge",100);
    equip_armor(Armour"/cloth05");
    equip_armor(Armour"/cloak03");
    wield_weapon(Weapon"/mace03");
    set( "inquiry", ([
         "son" : "@@ask_son" ,
         "falady" : "@@ask_falady" ,
           ]) );
}

void init()
{
     ::init();
     add_action("to_comfort","comfort");
}

void ask_son(object who)
{
     object *items;
     int i;
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
           tell_object(who,
           "�ҵ���������, �������밬��, �����������? ���Ƕ���Ӣ�µ���ʿ.\n"
           );
           return ;
           }
     tell_object(who,
     "�ʺ��˿���������Ǹ�İ���˶����ش���.\n"
     );
     return;
}

void ask_falady(object who)
{
     object *items;
     int i;
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
           tell_object(who,@MSG1
�ҵĴ���ӷ�����, ���������? ����Ӣ�µ���ʿ. ����ȴ���ҵ�
ս����.
�ʺ�˵������ʱ, ���Ծ��ĵ�����\��\��.
MSG1
           );
           return ;
           }
     tell_object(who,
     "�ʺ��˿���������Ǹ�İ���˶����ش���.\n"
     );
     return;
}

void ask_air(object who)
{
     object *items;
     int i;
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
           tell_object(who,@MSG2
�ҵĶ����Ӱ���, ���������? ����һ������ġ�����ʿ. ���Ѿ���
��û�м�������.
MSG2
           );
           return ;
           }
     tell_object(who,
     "�ʺ��˿���������Ǹ�İ���˶����ش���.\n"
     );
     return;
}

int to_comfort(string str)
{
    object *items,who;
    int i;
    
    if (!id(str)) return 0;
    
    who=this_player();
    items=all_inventory(who);
    for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
               write(@MSG3
������ȥ��ο�ʺ�, ��������ѧ�������Ȥ������, �ʺ������.
���úö���.
Ȼ���ʺ���Ȼ��δչ��Ц��.������˼�������Ķ���.
��ʱ�ʺ����˵:
�Һ�˼���ҵĴ���ӷ�����, ����һ���������Ҫ��, ϣ�����ܰ���
�쵽, �Ǿ����Һ��������ټ���һ��, ��ʹ���������.
�ʺ��ó�һ�������,
ϣ��������Ҵ���ӵ�ʱ���ܹ�������ĸ�׺�������.
MSG3
               );
               items[i]->set("quest_item/queen_amulet",1);
               return 1;
               }
    tell_object(who,
     "�ʺ��˿���������Ǹ�İ���˶��������.\n"
     );           
    return 1;
}
