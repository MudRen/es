#include <mudlib.h>

inherit MONSTER ;

void create () {
	::create() ;
	set_level(19);
	set_name( "soraz", "������");
	add( "id", ({ "archmage" }) );
	set_short("��ħ��ʦ������");
	set_long(@CLONG
����ע����������ʱ����о���һ�����ε�ħ�������������
˼�룬����޿��ܵ�������
CLONG
	);
	set( "no_attack", 1) ;
	set( "gender", "male") ;
	set( "race", "elf") ;
	set_perm_stat("intelligence", 30);
	set ("inquiry", ([
"magic" : "Magic is a complex and dangerous art. First, you must learn\n"+
"the read magic spell, which I will teach you. Second, you must find a\n"+
"scroll of a new spell and cast the read spell on the scroll. This will\n"+
"teach you the new spell. You can cast the new spell if you are skilled\n"+
"enough and if you have enough spell points.",
"spells" : "There are many spells you can learn; type \"help spells\" to\n"+
"see them all. I will teach you the read spell but you must learn the\n"+
"rest from scrolls."
	]) ) ;
}
