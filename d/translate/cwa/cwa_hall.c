#include <mudlib.h> 

inherit ROOM;

void create()
{
	::create();
	set_short("Color Wolf Association", "ɫ��Э��" );
	set_long(
"You are in the great hall of Color Wolf Association.\n",
      "�����ɫ��Э�����, �㿴����˽����еض���΢Ц. ����ǧ��\n"
"��Ҫ��ɱ��˽���׬�����, ��������һ������ܵ���ȺΧ��, ������\n"
"��֮��!\n"
      "������������ɫ��Э��, ����������ȿ�������ǽ�ϵ�˵����\n"
"��(sign)��˵. ���ߵ�ǽ������һ��Ӣ�۰�(list), ����������ɫ��Э\n"
"���Ա������.\n"
	);
	set( "light",1 );
	set( "exits", ([
		"up" : "/u/s/supertramp/cwa/cwa_club"
	]) );
	set("pre_exit_func", ([
		"up" : "check_color"
	]) );
	set("item_desc", ([
		"sign" : @SIGN
===============================================================
===============================================================
SIGN
	])  );

	set("c_item_desc", ([
		"sign" : @C_SIGN
==============================================================
  ɫ��Э����ŵ�ٴ����ʷ���ƾ�, ��Ա������֯. ���Ļ�Ա�Ǹ�
  �������г��˵�����, 毺õ����, ��ŵ������Լ�����Ҫ�� - 
  ������ʥ��Ʒ��. ����(��)��߱�����������������, ���ھͼ���
  ��ʥ��ɫ��Э���!
==============================================================
C_SIGN
	])  );

	set("item_func",([
		"list" : "look_list"
	]));

	set("objects", ([
		"pig8" : "/u/s/supertramp/cwa/pig"  ]));
}

int look_list() {
	cat("/u/s/supertramp/cwa/memberlist.txt");
	return(1);
}

void init()
{
        add_action("join","join");
}

int join()
{
	if((int)this_player()->query("CWA")==1)
		return notify_fail(can_read_chinese()?
"�����Ѽ���ɫ��Э����!\n" :
"You are already a member of CWA!\n");

	write(can_read_chinese()?
"����Ϊ��ʥ��ɫ��Э��������ü�����? ��ɵ��!\n" +
"ɫ��Э���Ա�Ƕ��Ƕ��������еľ�Ӣ! ����Ϊ��\n" +
"���ʸ���? ����������Ϊ���Լ���, �ͷ��Ÿ�Э\n" +
"���е��κ�һλ����, ���ǽ���������������\n" +
"��! ף����!" :     
"Do you think it's THAT EASY to join CWA? Don't be silly!\n" +
"Send a mail to the elders in CWA first, they will decide if\n" +
"you can join or not. Send them a mail NOW!\n");
	return(1);
} 


int check_color()  {
	if((int)this_player()->query("CWA")!=1)  {
		write(can_read_chinese()?
"\n\n\n��˽�����ȵ�������, С��! ����Ϊ����˭? �����վס!\n\n\n\n"+
"��Ӿ����лع�����, ����Ҳ����ð����˽估�κ�ɫ��Э���Ա��\n" :
"\n\n\nThe evil pig shouts: Stop! Kid! Who do you think you are? FREEZE!\n\n\n\n"+
"You awake, but you are now afraid of the evil pig and CWA members very much!\n"); 
		return(1);
	}
	return(0);
}


