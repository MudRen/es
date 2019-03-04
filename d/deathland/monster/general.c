
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	object ob1,ob2,ob3,ob4,ob5,ob6;
	
	::create();
	seteuid(getuid());
	set_level(18);
	set_name( "Dwarf general karl", "���˽�������" );
	add ("id", ({ "general", "dwarf","karl" }) );
	set_short( "a dwarf general karl", "���˽�������" );
	set_long(
	" an old general named called karl\n",@DESC
һ�����ϵĽ�������, �Ѿ��о����˵�ս�����������, ����������Ȼ��
��������,���������ǻ�ȴ���������������Խ��Խ������.ֻ���������
��������ʵ��̫����,���������ֻ���������һ������,����������һ
��֪.
DESC
    );

    set("inquiry",([
        "troll":"@@ask_troll",
        "notes":"@@ask_notes",
        "model":"@@ask_model",
        ]) );
        
    set( "alignment",700);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "��" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "con", 29);
	set("wealth", ([ "gold": 5]) );
	set_natural_weapon(12,13,17);
	set_natural_armor(35,40);
	set ("aim_difficulty", ([ "critical":30,"vascular":35]) );
	set ("special_defense",([ "all": 35,"none":35 ]) );
    set ("weight", 300);
    set ("alignment",700);
    set_skill("parry",97);
    set_skill("blunt",97);
    set_skill("block",88);
	wield_weapon(Weapon"/hammer02");
	equip_armor(Armour"/plate02");
	equip_armor(Armour"/leggings01");
	equip_armor(Armour"/boots02");
	equip_armor(Armour"/shield01");
	equip_armor(Armour"/helmet01");
	
}

void ask_troll(object who)
{
  tell_object(who,@MSG1
����,�����Ѿ���������ս�����������,���ǵ�һ��һ��
�Լ����ֵĹ���ģʽ�ͷ���,��ͱ������о�͸����.����
����Ҫ�ص����������Լ��ָ����ǳ�ǿ ,���������˶�
ս��ʱ��,�㲻��һ����������������Ļ�,������Ϣ����
��ս���Ļ�,����ԵĽ���һ�������ȱ�ľ���
MSG1
  );
  return ;
}

void ask_model(object who)
{

   tell_object(who,@MSG2
��Щģ����һ���Ӷ��������̴��,����פ����˵�ʱ,��
��������һͬ�о�������ɹ� ,������������������
�����������.
MSG2
                   );
   return;
}

void ask_notes(object who)
{ 
   tell_object(who,@MSG3
��Щ��¼����������,�ǲ���?
��������֤�����Ǹ����ߵĻ�.....
MSG3
               );
   return;
}

//int accept_item(object ob1,object ob2)
//{
//     if (!ob2 || (int)(ob2->query("echo_quest_card"))!=1) return 0;
//     if ((int)(ob2->query("echo_quest_card"))==1) {
//        if( ob1->query("name")!=ob2->query("someone_id") )
//          {
//          tell_object(ob1,
//          "�����⿨Ƭ�ǷǷ�������.�����Ҳ��ܰ����������.\n"
//           );
//          //command("drop card\n"); 
//          }
//        else {
//        tell_object(ob1,can_read_chinese(ob1) ?
//        " "
//        :
//        " \n"
//        );
//       ob2->move(ob1);
//       tell_object(environment(),"�궼��˹�ѿ�Ƭ����"+ob1->query("c_short")+"\n");
//          }
//     }     
//     return 1;  
//}
