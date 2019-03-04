
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short("The church of dwarf village","���˴���Ľ���");
  set_long(@Long
һ����͵����������������ط�,�����ﵽ�������ϵ���ͽ,���˵�����ʮ��
��,�������ǵĴ����ܹ������������ຣ,����������ֽ�����������ΰ�Ĵ��
��.������\��\��\�����һ���ǳ��޴������(statue)��,����ǰ��һ����̳(altar),
�������ų��α�����������,������ͽ����ר�ĵ���(pray).
Long
);
set("exits",([
    "north":Deathland"/village/v41",
             ]));
set("c_item_desc",([
    "altar":@Altar
һ����ֵļ�̳,�������һ��.
Altar
    ,"statue":@Statue
�޴�����������������ǰ,�ƺ�������������,��ϸ��һ����Сʱ��Ķ���֮
�г������ֵĴ�ħ��������ģ��,�����Ǵ�˵�еĶ��� Evil Yang.��������
����һ������� ( trident ) ,ָ��ңԶ������.���� Echo ��ס�ĵط�.
Statue
    ]) );
set("objects",([
    "believer#1":Monster"/believer",
    "believer#2":Monster"/believer",
    "priest":Monster"/archbishop",
             ]) );
::reset();
}

void init()
{
	add_action("do_pray","pray");
}
int do_pray()
{
	tell_object(this_player(),"��ר�ĵ������ Yang �� ...\n");
	this_player()->save_me();
	"/adm/daemons/backup"->user_backup(this_player());
	return 1;
}
