// File: /d/deathland/city/church.c
// Generated by Roommaker Sat Nov 11 15:06:00 1995

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("���˹��ȵĽ���");
	ob->set_long( @LONG_DESCRIPTION
һ����͵����������������ط�,�����ﵽ�������ϵ���ͽ,���������
��ս��֮��, �������������ǵĴ����ܹ������������ຣ, ��˽���������
��ΰ�Ĵ����.������\��\��\�����һ���ǳ��޴������ (statue) ��,����ǰ��
һ����̳(altar),�������ų��α�����������,������ͽ����ר�ĵ�����.
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "c_item_desc", ([ 
		"altar" : "һ����ֵļ�̳,�������һ��.\n", 
		"statue" : "@@look_statue" ]) );
	ob->set( "exits", ([ 
		"south" : "/d/deathland/city/c4" ]) );
	ob->set( "objects", ([ 
		"priest" : "/d/deathland/monster/priest", 
		"believer#2" : "/d/deathland/monster/believer", 
		"believer#4" : "/d/deathland/monster/believer", 
		"believer#1" : "/d/deathland/monster/believer", 
		"believer#3" : "/d/deathland/monster/believer" ]) );
	ob->reset();
}