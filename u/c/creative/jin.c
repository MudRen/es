#include <mudlib.h>
#include <ansi.h>

inherit MONSTER;

void create ()
{
 ::create();
 set_level(19);
 set_name("jin ke","����");
 add("id","ke");
 set_short("��̿� ����");
 set_long(@C_LONG
 �պ������ľ���������ɱ�����������书��������������ɱ�ְ��������
 �����︺��ѵ��ɱ�ֵĹ�����ֻ������Ŀ���գ���ü������������ʲô����
 ��Ҫ�˰�æ.\n
 @C_LONG
 );
 set("gender","male");
 set("race","drow");
 set("unit","��");
 set_perm_stat("str",30);
 set_perm_stat("int",30);
 set_perm_stat("kar",30);
 set_perm_stat("dex",30);
 set_perm_stat("pie",30);
 set_perm_stat("con",30);
 set("max_hp",3000);
 set("hit_points",3000);
 set_natural_armor(60,35);
 set_natural_weapon(72,29,55);
 set("chat_chance",10);
 set("att_chat_output",({
 "������Ц��������Ұ��?!����!!\n"
  }));
 wield_weapon("/d/island/hole/weapon/axe1.c");
 set("inquiry",([
  "help": "@@ask_help",
  "task": "@@ask_task"]);
}

void ask_help(object asker)
{
 write(@D_LONG
 ����������������,�����Щ����,�������ɱ��,�����������һ��(task)
 ������������,�һᱨ�����\n
 @D_LONG
}

void ask_task(object asker)
{
write(@C_LONG
 ��ε�������ɱrashudi...
 @C_LONG
}


