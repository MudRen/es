#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("gold bow","���ȵ��ϸ��");
       add("id",({"gold","bow",}) );
       set_short("���ȵ��ϸ��");
	   set_long(@C_LONG
�㿴��һ�ѽ�ɫ�Ĺ������滭�������Ļ�����㣬����������
��Ȼ����������ã�Ҳ��\��\��\Ӳ�Ĺ���Ҳ��ֱ�ӹ�������
C_LONG	);
	
	set( "unit", "��" );
 	set( "weapon_class", 35 );
        set("type","blunt");
	set( "min_damage", 18 );
	set( "max_damage", 35 );
	set( "weight", 50 );
	set( "value", ({ 310, "gold" }) );
        set_c_verbs( ({
          "%s���һ����������%s",
          "%s�������ң�����쬵�һ����һ������Ϯ��%s",
          "%sһ��������ɽ���ù���������%s��",
          "%s����һ����Х������������ֻ��������%s",
         }) );
        set( "extra_skills",(["dodge":10])); 
}

