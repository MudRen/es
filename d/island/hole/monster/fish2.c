#include <../hole.h>        
        
inherit MONSTER;
void create ()
{
	::create();
	set_level(8);
	set_name( "Dragon Fish","����" );
	set ( "id",({ "fish" }) );
	set_short( "����" );
	set_long(@LONG
����һ���޴�ĺ����㡣
LONG
		);
	set( "likefish",1 ) ;
	set( "unit","��" );
	set( "alignment",1000 );
	set( "moving",1 );
	set( "speed",30 );
	set_natural_weapon( 35,5,16 );
	set_skill( "unarmed",80 );
	set_natural_armor( 25,8 );
	set_c_verbs( ({ "%s�þ޴��β��ɨ��%s","%s�ſ����������Ĵ���ҧ��%s" }) );
	set_c_limbs( ({ "����","β��","ͷ��" }) );
	setenv( "C_MIN","һ���ܴ�β��$N��������˹���" );
	setenv( "C_MOUT","һ���ܴ�β��$N�������$D���˹�ȥ" );
}