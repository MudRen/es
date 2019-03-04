#include "../ekravia.h"

inherit MONSTER;

void create()
{
	object	hat, coat, pants;

	::create();
	set_level(9);
	set_name( "wounder magician", "ħ��ʦ" );
	add( "id", ({ "magician" }) );
	set_short( "����ħ��ʦ" );
	set_long(@LONG
ר�Ŵ������˻�Ц��ħ��ʦ�����������ͨ, ��һ�׺�ɫ����β��, ͷ
�ϴ���ע���̱��ĺ�ɫ��ñ�ӡ����ɵ�����������Կ��ŵı���, ����
���ݳ�������̾Ϊ��ֹ��ħ����
LONG
	);
	set_perm_stat( "str", 7 );
	set_perm_stat( "dex", 9 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "con", 7 );
	set_perm_stat( "pie", 10 );
	set_natural_weapon( 20, 9, 19 );
	set_natural_armor( 25, 9);
	set( "gender", "male" );
	set( "alignment", 200 );
	set( "wealth/silver", 100 );
	
	hat = clone_object( OBJ"black_hat" );
	coat = clone_object( OBJ"coat" );
	pants = clone_object( OBJ"pants" );
	hat->move(this_object());
	coat->move(this_object());
	pants->move(this_object());
	equip_armor(hat);
	equip_armor(coat);
	equip_armor(pants);

	set( "chat_chance", 15 );
	set( "chat_output", ({
		"ħ��ʦժ��ñ��, ���ڳ����й��ھ��˸�����\n",
		"ͻȻ��, ��ֻ���Ӵ�ñ������˳���, �ַɽ�ñ��, �ַɳ���, ���ɳ���"
		"��ȴ�ǰ�ֻ��\n",
		"ħ��ʦ����ñ��, ʾ������տ���Ҳ��\n",
		"ħ��ʦ��������һ��, һ��������˳���, Ʈ���������ա�\n",
		"ħ��ʦ����һ��, ���ϱ���һ������, ������ɢȥ��ֻ���Ƕ���ñ�ӵ���"
		"�ڵ�, ����ʧ�ˡ�\n",
		"һ��ѵĸ��Ӻ���Ԥ������ñ����ɳ�, ����һ�Ѳʴ�, �������ħ��ʦ"
		"����\n����ñ�������˳�����\n",
		"���˸���ħ��ʦ���ҵ�����, �׷װ�Ǯ�������ĸ�ñ���\n"
	}) );
}
