#include "nodania.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create();
	set_short( "��������" );
	set_long(@CLONG
��������վ��һ�����������ζ�ĵ��̵��У���ҵ��˵�ǵ���
��λ��һ��̤��ŵ���������صĶ����˿��ģ���������������������
������ҵ������Ѿ���ŵ�����ǳ����������ϣ�����׿�������ֺ���
������������Բ��ص��ı�ƭ���򵽴μ�Ʒ��
CLONG
	);
	set( "light", 1);
	set( "exits", ([
		"east" : NODANIA"nodania_r1"
	]) );
	set( "objects", ([ "trashcan": "/obj/trashcan" ]) );
	storeroom()->set( "objects", ([
		"bag#1" : "/obj/bag" ]) );
	replace_program(SHOP);
}
