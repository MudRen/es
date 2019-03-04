// post_office.c
#include "../island.h"
#include <mailer.h>

inherit ROOM;

void create()
{
	::create();
	seteuid(getuid()) ;
	set_short("��Ӫ�ʾ�");
	set_long(@C_LONG
������λ�ӳ������ʾ֣���Ϊ�������λ���������������ʾ��ǵ�
����Ӫ�ģ�����������Լ���(mail)�������������ϵ��ˣ��������˼���
���㣬Ҳ������������ȡ���ڹ�̨�Աߵ�ǽ����һ�Ų���(sign)˵�����
�������š�
C_LONG
	);
	set("light",1) ;
	set("exits", ([ "west" : ITOWN"town02" ]) ) ;
	set("pre_exit_func", ([ "west" : "dest_mailer" ]) ) ;
	set("item_func", ([ "sign" : "read_sign" ]) ) ;
}

void init()
{
	add_action("mail", "mail") ;
	add_action("help", "help");
	add_action("read_sign", "read") ;
        if( this_player() ) this_player()->set_explore( "eastland#8" );
}

int mail(string arg)
{
   object ob;

   seteuid("TEMP");

   ob = new(MAILER);
   ob->move(this_player());
   ob->start_mail(arg);
   return 1;
}

int help(string str)
{
    if (str == "mail") {
	this_player()->more(MAILER_LONG);
	return 1;
    } else return 0;
}

int read_sign (string str)
{
	if (str && str!="sign") return 0 ;
	write (@LONG
        ������ţ����ţ�
        
        �� ���� �� ���� mail ���㽫������ŵ�״̬ �� �� ? ����
                   ����״̬�£��õ�help��
        �� ���� �� ��ʽ�� mail [ppl's id] ��
LONG
     ) ;
	return 1 ;
}

int dest_mailer()
{
	object ob ;

	ob = present("mailer",this_player());
	if (ob) ob->remove() ;
	return 0 ;
}
