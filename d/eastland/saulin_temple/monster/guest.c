#include "saulin_monka.c"

void create()
{
	object ob1;
	::create();
	set_level(5);
	set_name( "temple guest", "�����" );
	add( "id", ({ "guest" }) );
	set_short( "�����" );
	set_long(@C_LONG
����һ���ϵķ��ͽ�������ǳ����ֵ������������½��㡣
�����ĺ��֣�����һ�������ӣ���Ц������ƺ�һ�㶼����...
C_LONG
   	        );
	set( "max_hp", 145 );
	set( "hit_points",145 );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 500 );
	set( "wealth/silver", 10 );
//	set( "speed", 50);
//	set( "forgetful", 1);
//	set( "moving", 1);
	seteuid( getuid() );
	set( "wimpy", 70);
	set_perm_stat("strength",10);
	set_perm_stat("dexterity",10);
	set_perm_stat("piety",10);
	set_natural_weapon( 8, 4, 9 );
	set_natural_armor( 25, 10 );
	set_skill("dodge",50);  
	set_c_verbs( ({ "%s�������ӣ����ص���%s������ȥ",
			"%s���һ������ȭͷ��%s����",  
			"%sһ����������ǰ����ײ��%s", 
		}) );
	set_c_limbs(({ "������ͺͷ", "�ʷʵ�����", "���͵ľ���", "�ִֵķ���"}));
	ob1 = new( SAULIN_OBJ"basket" );
	ob1->move(this_object());
}
/*

int catch_huntee( object who )
{
    tell_room( environment(this_object()), 
      "����ʹ��һ��: ���� "+who->query("c_name")+" ��ǿ�����ˣ�������� !\n"
      ,  ({ this_object(), who }) );
    tell_object( who, 
      "����ʹ��һ��: ���������ɱ�˲�գ�۵�ǿ����������� !\n" 
    );
    return 1;
}
*/
