#include "../moyada.h"

inherit WEAPON;

void create()
{
    seteuid( getuid() );
	set_name("Death Scythe", "��������");
	add ("id",({ "scythe", }) );
	set_short("��������");
	set_long(@C_LONG
һ�Ѻ�ʮ�ַ����Ĵ���������˵�������İ���������
�������������(cropp)��? 
C_LONG
	);
	set( "unit", "��" );
	set( "weapon_class", 21 );
        set( "type", "longblade" );
	set( "min_damage", 12 );
	set( "max_damage", 20 );
	set( "weight", 150 );
	set( "no_sale", 1);
	set( "nosecond", 1);
	set( "value", ({ 10, "silver" }) );
}

void init()
{
        add_action("to_cropp","cropp");
}

int to_cropp(string str)
{
      object ob;
      write(@ALONG
            
        ����������������˵: �������������! ����û�˸���˶Դ��ҡ�
        ��������������������������ɵ����в��ܲ�ˬ��������

ALONG
             );
      ob=new( MOYADA"monster/death_scythe" );
      ob->move( environment(environment(this_object())) );
      this_object()->remove();
      return 1;
}
