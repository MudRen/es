
#include <mudlib.h>
inherit MONSTER;

void create()  {
	::create();
	set_level(5);
	set_name("pig8");
	set("race","human");
	set("gender","male");
	set_short("The evil pig", "��˽�");
	set_long(
"\n",
"��˽���ɫ��Э����ػ���. ����ԲԲ������, ���Ķ���, ɫ���е�\n"+
"����. ����ʱ�����������������Һ! ���㿴�˾���ʮ�����, �����\n"+
"������, ��ǰ��������!\n"
	);
	set("no_attack",1);
	set("chat_chance",5);
	set("chat_output",({
"Pig8 says to you with its EVIL looking face:Believe in me and you'll\n"+
"have a permanent life!\n",
"��˽�ɫ���еĶ���˵���������ߵ�����!\n"
	}));
}

void init()  {
	if ((int)this_player()->query("CWA") == 1) {
		write(can_read_chinese()?
"�����Զ������ɫ���ػ�����˽����еض���˵��"+this_player()->query("c_cap_name")+"! �ҵ�����! ��ӭ��ؼ�!\n" :
"Welcome HOME! "+this_player()->query("cap_name")+"! My lovely child!\n");
		tell_room(environment(this_player()), ({
"Let's stand up to welcome "+this_player()->query("cap_name")+"'s coming\n",
"��˽��˷ܵ�˵�����������������ƻ�ӭɫ��Ӣ��"+this_player()->query("c_cap_name")+"�ĵ���!\n"}),
		this_player());
	} else {
		write(can_read_chinese()?
"�㻹δ̤������, ��������˽��������"+this_player()->query("c_cap_name")+"! ��ע����ܾ���! ��������ɫ����Ӧ�øϿ����������ʥ��ɫ��Э��!\n" :
"I've been watching you for a loooong time! "+this_player()->query("cap_name")+"! I think ppl\nas color as you better join us CWA ASAP!\n");
	}

}
