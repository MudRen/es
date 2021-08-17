//#pragma save_binary

// This is part of the TMI distribution mudlib.
// Please retain this header if you use this code.
// Coded by Sulam (12-8-91)
// Fixed to accept defaults correctly by Jubal (Dec15/91)
// Help added by Brian (1/27/92)
// Revised by Buddha for new variable access (6-21-92)
// Fixed a typo (posted by Bonzo) (6-3-93)  Fix put in by Guile
// Added Chinese name by Annihilator (12-14-93)

#include <mudlib.h>
#include <protects.h>
#include <ansi.h>

inherit DAEMON;

object link;
int chinese_mode;

int cmd_chfn( string arg )
{

	if((string)this_player()->query("name") == "guest") {
		write("���������Ӣ�����֣�");
		input_to( "guest_name" );
		return 1;
	}

	link = this_player()->query_link();

		write( @TEXT
�޸����ﱳ������:
______________________________________________________________
�� [] �����ÿ�����ϵ�Ԥ��ֵ�������Ҫʹ��Ԥ��ֵ��ֱ�Ӱ� ENTER
�����ɡ�

TEXT
		);
		printf("%s [%s] : ","��ʵ����",(string)link->query("real_name"));

	input_to("new_name");
	return 1;
}

protected void guest_name(string rname)
{
	if( rname && strlen( rname ) > 0 ) {
		this_player()->set( "id", ({ rname, "guest" }) );
		this_player()->set("guest_name", rname );
//		this_player()->set("cap_name", "Guest, " + capitalize(rname) );
	}
	printf( "%s [%s] : ","��������",(string)this_player()->query("c_name"));
	input_to("guest_chinese_name");
}

protected void new_name(string rname)
{
	if( rname && strlen( rname ) > 0 ) {
		link->set("real_name", replace_string(rname,ESC,""));
          link->set("real_name", replace_string(rname,CSI,""));
		link->save_data() ;
	}
	printf( "%s [%s] : ","��������",(string)link->query("c_name"));
	input_to("new_chinese_name");
}

protected void new_chinese_name(string ncname)
{
	string tmp1,tmp2;
	if( !ncname || ncname == "" ) ncname = link->query("c_name");
	if( ncname && strlen( ncname ) > 0 ) {
	        if(this_player()->query("make-up"))
	          {
	                write("�����ѵ�����ٸ������\n") ;
	              return ;
	           }
		if( (member_array(ncname, PROTECT_C_NAME) != -1) &&
			!member_group(geteuid(this_player()),"admin") ) {
			write("�Բ�����Ϊĳ��ԭ���㲻���������֣���������һ���ɡ�\n");
			printf( "%s [%s] : ","��������",(string)link->query("c_name"));
			input_to("new_chinese_name");
			return;
		}
		if( sscanf(ncname,"%s(%s",tmp1,tmp2)==2) {
			write("�Բ��������в��ܺ������š�\n");
			printf( "%s [%s] : ","��������",(string)link->query("c_name"));
			input_to("new_chinese_name");
			return;
		}
		if( strlen( ncname ) > 14 ) {
			write( "�Բ��������������̫���ˣ�������� 7 ���������ڡ�\n");
			printf( "%s [%s] : ","��������",(string)link->query("c_name"));
			input_to("new_chinese_name");
			return;
		}
//		if( ncname[0]>='a' && ncname[0]<='z' )
			ncname = replace_string(ncname,ESC,"");
			ncname = replace_string(ncname,CSI,"");
		link->set("c_name", ncname);
		this_player()->set("c_name", ncname);
		this_player()->set("title",this_player()->query_title(this_player()));
		link->save_data();
	}
        printf( "%s [%s] : ","�����ʼ���ַ",link->query("email"));
	input_to("new_email");
}

protected void guest_chinese_name(string ncname)
{
	if( !ncname || ncname == "" ) ncname = link->query("c_name");
	if( ncname && strlen( ncname ) > 0 ) {
	        if(this_player()->query("make-up"))
	          {
	                write("�����ѵ�����ٸ������\n") ;
	              return ;
	           }
		if( (member_array(ncname, PROTECT_C_NAME) != -1) &&
			!member_group(geteuid(this_player()),"admin") ) {
			write(
				"�Բ�����Ϊĳ��ԭ���㲻���������֣���������һ���ɡ�\n");
			printf( "%s [%s] : ","��������",(string)link->query("c_name"));
			input_to("new_chinese_name");
			return;
		}
		if( strlen( ncname ) > 14 ) {
			write("�Բ��������������̫���ˣ�������� 7 ���������ڡ�\n");
			printf( "%s [%s] : ","��������",(string)link->query("c_name"));
			input_to("new_chinese_name");
			return;
		}
//		if( ncname[0]>='a' && ncname[0]<='z' )
		ncname = replace_string(capitalize(ncname),ESC,"");
		ncname = replace_string(capitalize(ncname),CSI,"");
		this_player()->set("c_name", ncname);
		this_player()->set("title",this_player()->query_title(this_player()));
	}
}

protected void new_email(string e)
{
	if( e && strlen( e ) > 0 ) {
		link->set("email", replace_string(e,ESC,""));
		link->save_data() ;
	}
}

int help() {
	write(@HELP
ָ���ʽ: chfn

���ָ������������������Լ��ı������ϡ�

HELP
);
	return 1;
}
/* EOF */
