#include <../hole.h>        
        
inherit MONSTER;
void create ()
{
	::create();
	set_level(15);
	set_name( "Flesheater Fish","ʳ����" );
	set ( "id",({ "fish" }) );
	set_short( "ʳ����" );
	set_long(@LONG
����һ���׺���ʳ���㣬���������ʳ��
LONG
		);
	set( "likefish",1 ) ;
	set( "unit","��" );
	set( "alignment",-1000 );
	set( "killer",1 );
	set( "moving",1 );
	set( "speed",30 );
	set_natural_weapon( 60,15,40 );
	set_skill( "unarmed",80 );
	set_natural_armor( 40,10 );
	set( "c_killer_msg",
	"ʳ���㿴�����ǡ��������������䡻�ļ�����ɫ���е����������ǻ�\n\n" );
	set_c_verbs( ({ "%s�����а�ı�������%s","%s�ſ����������Ĵ���ҧ��%s" }) );
	set_c_limbs( ({ "����","β��","ͷ��" }) );
	setenv( "C_MIN","$NѸ�ٵ����˹���" );
	setenv( "C_MOUT","$N��������$D���˹�ȥ" );
}