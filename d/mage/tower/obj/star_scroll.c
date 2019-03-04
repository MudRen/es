//  Created by Yueh in Eastern Story 1995/11/10
#include <mudlib.h>
#include <daemons.h>
#define SLAB_FILE "/d/mage/data/slab.txt"
inherit OBJECT;

void create()
{
	set_name( "white magic scroll", "��ɫħ������" );
	add( "id", ({ "scroll" }) );
	set_short( "��ɫħ������" );
	set("long","@@desc");
	set( "unit", "��" );
	set( "weight", 5 );
	set( "no_sale", 1 );

}

void init()
{
        add_action( "study_scroll", "study" );
}

int study_scroll(string arg)
{
        object env,me;
	int points,total_points,percentage;
	me=this_player();
        if( !arg || arg!="scroll" )
                return notify_fail("���о�ʲ�᣿\n");
        if ((this_player()->query("spell_levels/misc")< 50))
                return notify_fail("��Щ�ǿ�ͼ���������ĳ�ַ��������ܣ������㲻֪����ȷ��ʹ�÷�ʽ\n��������������ħ�������������ɣ�\n");
	points=(int)me->query_explore_points();
	total_points=EXPLORE_D->query_total_explore();
	percentage=points*100/total_points;
	if ( percentage < 60)
return  notify_fail("��Щ�ǿ�ͼ���������ĳ�ַ��������ܣ����о��˰��죬���ǲ�֪����Щ�ǿ�\nͼ�ֱ��Ǵ�����۲�ģ�������̽�նȻ�������\n");

if (!undefinedp(this_player()->query("spells/astral-gate")))
return notify_fail("�㿴�����ǿ�ͼ������Щ�ǿյķֲ��ǵø�����ˡ�\n");
	write("�㿪ʼ��ϸ�о������ϵ��ǿ�ͼ .... \n\n");
	tell_room( environment(me), sprintf("%s�������Ὺʼ������\n", me->query("c_name")), me);
	printf("���ᷢ���˰�ɫ�Ĺ�â�������˼��ٿŵİ�ɫ���ǵ�Ӱ��Χ��������ٵ��ƶ���.... \n ...\n ...\n");
	tell_room( environment(me),sprintf("\n%s���ϵľ��ᷢ���˰�ɫ�Ĺ�â�������˼��ٿŰ�ɫ���ǵ�Ӱ��Χ����%s���ٵ��ƶ�.... \n",me->query("c_name"),me->query("c_name")), me);

	call_out("effect",1,me);
        return 1;
}
void effect(object reciter)
{
string fame;
seteuid(getuid());
fame = "     "+(string)reciter->query("c_name")+"("+
                (string)reciter->query("name")+")"+" � "+
                "/adm/daemons/weather_d"->query_c_game_time()+" ϰ���ǿ�֮�� !!\n";
                write_file(SLAB_FILE, fame+"\n");
write("�ӹ۲����ǵķֲ����ƶ��������Գ����ʹ���ǿ�֮�ţ���\n> ");
	tell_room( environment(reciter), sprintf("\n��ɫ���ǵ�Ӱ��������ģ������������ʧ������.... \n\n> " ));
	this_player()->set("spells/astral-gate",0);
	this_player()->set("spells/star-memory",0);
	remove();
}

string desc()
{
if (undefinedp(this_player()->query("spells/astral-gate")))
return("���Ű�ɫ�������滭�˺ܶ���ǿ�ͼ������ϸ�о�(study)�������(scroll)��\n");
else
return("���Ű�ɫ�������滭��ѧϰ�ǿ�֮�ű�֪�ĸ����ǿ�ͼ��\n");
}

