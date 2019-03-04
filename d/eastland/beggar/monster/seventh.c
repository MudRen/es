#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "seven-bag beggar", "�ߴ�����" );
	add( "id",({"beggar","seven"}) );
	set_short( "ؤ�� �ߴ�����" );
	set_long(@C_LONG
ؤ���ߴ������ڰ��е�λ��������, ���������ڽ̵�������ӵ��书�� 
C_LONG	
        );
        set( "unit", "��" );
	set_perm_stat( "str", 22 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 20 );
        set("weight",650);
	set_skill( "dodge", 80 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "race","human");
	set( "gender", "male" );
	set( "alignment", 200 );
	set_natural_armor( 25, 10 );
	set_natural_weapon( 40, 18, 20 );
        set( "natural_weapon_class2", 40 );
        set( "natural_min_damage2", 15 );
        set( "natural_max_damage2", 25 );
	set( "wealth/gold", 60 );
        set("chat_chance",15);
        set("chat_output",({
          "�ߴ�����˵�������Բ���,����̼��λ�������?\n",
          "�ߴ�����˵�������ֽ�����,����������!!\n"                        
                                  }) );
	set_c_verbs( ({ "%s̤����ǰ��һ��ֱȭ����%s",
		"%sһ�� ��̫�泤ȭ����˫ȭֱȡ%s",
		"%sһ��  ���������������������%s", 
		"%sһ�� ���ͻ���բ������ȭ��磬ֱȡ%s",
                   }) );

}
