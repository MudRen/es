#include <mudlib.h>
inherit "/std/poison.c";

void create()
{
	seteuid(getuid());
	set_name("opiate","�Ի���");
	set_short("�Ի���");
        set_long(
		"һ��С͵����ǰ��������, ������ԡ�\n"
        	"������� poison someone ����ĳ�˵�����\n"
	);
	set( "unit", "��" );
	set_duration(20);
	set_effect(5);
	set_type("slow");
	set_times(2);
	set("poison_msg","%s��ס�ĵ�ͷ, ����Ҫ˯����...\n");
	set("poison_method","%s����%s��ȼ$P");
	set("value",({ 320,"silver"}));
}

/* should be higher for thief and healer */
/* if fault , return 1 */
int checkfault(object me,object target)
{
	int rate,level,iq,dex,skill,kar;
	int diff = 30;

	level = (int)me->query_level()-(int)target->query_level();
	iq = (int)me->query_stat("int")*4-(int)target->query("int");
	kar = (int)me->query_stat("kar")*3-(int)target->query("kar");
	dex = (int)me->query_stat("dex")*2-(int)target->query("dex");

	rate = level+(iq+kar+dex)/3;
	if ( (string) me->query("class") == "thief" ) {
		rate += iq/4; 
	} else {
		skill = (int)me->query_skill("venomlogy");
		rate = rate * skill/90;
	}
	if ( rate <= 5 ) rate = 5; /* hehee *grin */
	tell_object(me,sprintf("rate = %d\n",rate));
	if ( random(rate) > diff)
		return 0;
	else
		return 1;
}

