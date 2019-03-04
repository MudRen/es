//  Created by Yueh in Eastern Story 1995/11/10
#include <mudlib.h>
#define SLAB_FILE "/d/mage/data/slab.txt"
inherit OBJECT;
void create()
{
	set_name( "blue magic scroll", "��ɫħ������" );
	add( "id", ({ "scroll" }) );
	set_short( "��ɫħ������" );
	set("long","@@desc");
	set( "unit", "��" );
	set( "weight", 5 );
	set( "no_sale", 1 );
}


void init()
{
        add_action( "recite_runes", "recite" );
}

int recite_runes(string arg)
{
        object env,me;
	me=this_player();
        if( !arg || arg!="runes" )
                return notify_fail("������ʲ�᣿\n");
        if ((this_player()->query_skill("runes")< 90))
                return notify_fail("�������������������ʲ�᣿\n");
        if ((this_player()->query("spell_levels/black-magic")< 50))
                return notify_fail("�������˰��죬���ǲ�֪����ȷ��ʹ�÷�ʽ���������Ժ�ħ�������������ɣ�\n");
if ((undefinedp (this_player()->query("spells/lightning"))) || (this_player()->query("spells/lightning")< 3))
return  notify_fail("�����������ģ�������Ŀǰ��Ļ������ȼ���֪�������ʹ�ã�\n");

if ((this_player()->query("spells/ether-bolt")== 8)||(this_player()->query("spells/fireball")== 7))
return notify_fail("���Ѿ�ѧ�������ߵȹ���ħ�����޷���ѧ�ˣ�\n");

if (this_player()->query("spells/lightning")== 4)
return notify_fail("�����������ģ���������ļǵø�����ˡ�\n");
	write("�㿪ʼ���о����ϵ����ģ����������ꡤ������̹....��\n\n");
	tell_room( environment(me), sprintf("%s�������Ὺʼ�����\n", me->query("c_name")), me);
	printf(set_color("���ᷢ������ɫ�Ĺ�â�������˼����ŵ�����ĵ�����Χ���������ܿ����ƶ�������ʱ�������.... \n ...\n ...\n", "HIB") );
	tell_room( environment(me), set_color(sprintf("\n%s���ϵľ��ᷢ������ɫ�Ĺ�â�������˼����ŵĵ�����Χ����%s���ܿ����ƶ�������ʱ�������.... \n",me->query("c_name"),me->query("c_name")),"HIB" ), me);

	call_out("effect",1,me);
        return 1;
}
void effect(object reciter)
{
string fame;
seteuid(getuid());
fame = "     "+(string)reciter->query("c_name")+"("+
                (string)reciter->query("name")+")"+" � "+
                "/adm/daemons/weather_d"->query_c_game_time()+" ϰ�û�����[4] !!\n";
                write_file(SLAB_FILE, fame+"\n");
	write("�ӹ۲�����������ƶ��������Գ����ʹ�û�����[4]����\n> ");
	tell_room( environment(reciter), sprintf(set_color("\n����ĵ���������������������ʧ������.... \n\n> ", "HIB") ));
	this_player()->set("spells/lightning",4);
	remove();
}

string desc()
{
if ((this_player()->query_skill("runes")< 50))
return ("������ɫ������д��һЩ�㿴������������֡�\n");
else
if ((this_player()->query_skill("runes")< 90))
return ("������ɫ������д��һЩħ�����֣�������ֻ������һ�룬��������ħ�����ֵ���ʶ�������ɡ�\n");
else
if ((undefinedp (this_player()->query("spells/lightning"))) || (this_player()->query("spells/lightning")< 3))
return ("������ɫ���������ƺ������������������ģ�������Ŀǰ��Ļ������ȼ���֪�������ʹ�á�\n");
else
if (this_player()->query("spells/lightning")== 4)
return("������ɫ����������������������ļ������ġ�\n");
else
return("����Ի��������˽⣬����������ƺ��ǻ�������һ�����ģ���������ǰ��û������Щ���ģ�\n����������(recite)��Щ����(runes)������\n");
}

