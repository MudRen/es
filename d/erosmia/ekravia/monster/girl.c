/*
	���СŮ���� QUEST �ĵ�һ������
*/
#include "/d/erosmia/ekravia/ekravia.h"
#include <mudlib.h>

inherit MONSTER;
inherit MESSAGE;

int		looked;

void	create()
{
	::create();
	set_level(3);
	set_name( "little girl", "СŮ��" );
	add( "id", ({ "girl" }) );
	set_short( "һ��СŮ��վ��ǽ��, ������" );
	set_long(@LONG
�㿴��һ��Լʮ�����ҵ�СŮ������������ɫ��װ��ͷ�ϴ�������ɫ��
���ñ, һ˫���ô����۾�������а�ؿ����㡣
LONG
	);
	set( "gender", "female" );
	set( "alignment", 100 );
	set( "no_attack", 1);
	looked = 0;
}

void	init()
{
	add_action( "do_look", "look" );
	::init();
}

int		do_look( string s )
{
	object	target;


	if (!s) return 0;
	target = present(s, environment(this_player()) );
	if ( (!target = present(s, environment(this_player())) ) ||
		(target != this_object()) )	return 0;
		
// ��ȷ�� player �������������СŮ��, ��ʼ�ɻ���!
	tell_room( environment(this_object()), emote_message_other(
		"$NS��$GS������Ͷ��СŮ�����ϡ�\n", this_player()),
		({ this_player(), this_object() }) );
	tell_object( this_player(), query("long") );
// СŮ����������Ķ�����
	
	if (looked)	return 1;
	looked = 1;
	call_out( "do_disappear", 5, this_object(), this_player() );
	return 1;
}

void	do_disappear( object me, object player )
{
	if (environment(me) != environment(player)) return;
	
	emote( "$NS�ſ�˫��, ��������Ц������$NO��ߡ�Ȼ������һ˲��,\n" +
		"����ͬ������¥����ʧ��, ֻ����������а��Ц���ڿ����л�����...\n",
		me, environment(player), player );
	find_object_or_load( QUEST"girl" )->girl_disappear();
}