#include "../ekravia.h"
inherit OBJECT;

int		charge;
int		use_card();

void	create()
{
//	::create();
	set_name("silver card");
	set_short("����");
	set( "long", "@@long_desc");
	add( "id", ({"card", "silver card"}) );
	set( "weight", 0);
	set( "unit", "��");
	set( "value", 0);
	set( "no_drop", 1);
	charge = 10;
}

string	long_desc()
{
	string	s;
	s = sprintf("%s\n%s%s%s\n", "����һ����ɫ�Ŀ�Ƭ, ����ӡ����ŵ�õ�ı�־",
			 "��������������ʹ��", chinese_number(charge), "�Ρ�" );
	return s;
}

/*
ʹ�ÿ�Ƭ���뷿��ʱ������, ������ϻ��� charge �Ļ��򴫻� 1,
���򴫻� 0��
*/
int		use_card()
{
	if (--charge > 0)	return 1;
	call_out( "remove_card", 5, this_player(),this_object() );
	if (charge == 0)	return 1;
	return 0;
}

void	remove_card( object player, object this_ob)
{
	tell_object(player, "�����Ĵ����Ѿ������ˡ�\n");
	this_ob->remove();
}
