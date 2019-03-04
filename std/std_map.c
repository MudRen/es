//#pragma save_binary

// map.c
// This object can show player a map in virtual areas.
// Created by Annihilator@Eastern.Stories
// Last revision: 11-07-93

#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>

#define TERRAIN "/adm/daemons/virtual/terrain_daemon"

int width, height, flag;
string bar;
int	center_x, center_y;
string virtual_server;

void 	set_size( int w, int h );
void 	set_center_coordinate( int x, int y, string v_server);
int		query_center_x();
int		query_center_y();
string	query_virtual_server();

void create()
{
	set_size( 7, 7 );
}

init()
{
	add_action("read_map", "read");
}

void set_size( int w, int h )
{
	int i;

	if( w>2 ) width = (w-1) / 2;
	if( h>2 ) height = (h-1) / 2;
	bar = "+-";
	w = width * 2 + 1;
	for( i=0; i<w; i++ )
		bar += "---";
	bar += "+\n";
}

void 	set_center_coordinate( int x, int y, string v_server)
{
	center_x = x;
	center_y = y;
	virtual_server = v_server;
	flag = 1;
}

int		query_center_x()
{
	return center_x;
}

int		query_center_y()
{
	return center_y;
}

string	query_virtual_server()
{
	return virtual_server;
}

int read_map(string arg)
{
	object env;
	int x, y, i, j;
	string str, legend, tk, tk_color,v_server;

	if( arg=="legend" ) {
	write( @C_LEGEND
�����ǵ�ͼ��������ʾ���ֵ��ε�ͼ��:
------------------------------------------------------
	::		ƽԭ
	oo		���ԡ��ݴ�
	OO		ɭ��
	/\\		ɽ��
	^^		ɽ��
	&&		ɳĮ
	++		��·
	[]		����
	%%		����
	==		ˮ�򡢺���
	~~		����
	 *		������
------------------------------------------------------
��ͼ����� <*> ��ʾ��Ŀǰ��λ�á�
C_LEGEND
		);
		return 1;
	}

	if( arg!="map" )
		return notify_fail("��ʲ�᣿\n");

	if( flag ) {
		v_server = query_virtual_server();
		x = query_center_x();
		y = query_center_y();
	} else {
		env = environment(this_object());
		if( living(env) ) env = environment(env);
		if( !env || !(v_server= env->query("virtual_server")) )
			return notify_fail("��ͼֻ����Ұ�����ʹ�á�\n");
		x = (int)env->query("x_coordinate");
		y = (int)env->query("y_coordinate");
	}
	str = bar;
	for( i=-height; i<=height; i++ )
	{
		str += "| ";
		for( j=-width; j<=width; j++ ) {

			
			legend = v_server->query_legend( x+j, y+i );
			switch( legend[0] ) {
				case 'P' : tk = "::";	tk_color = HBGRN;	break;
				case 'F' : tk = "OO";	tk_color = HBGRN;	break;
				case 'B' : tk = "oo";	tk_color = HBGRN;	break;
				case 'M' : tk = "/\\";	tk_color = HBYEL;	break;
				case 'H' : tk = "^^";	tk_color = HBYEL;	break;
				case 'R' : tk = "++";	tk_color = HBRED;	break;
				case 'T' : tk = "[]";	tk_color = HBMAG;	break;
				case 'S' : tk = "%%";	tk_color = HBYEL;	break;
				case 'W' : tk = "==";	tk_color = HBCYN;	break;
				case 'O' : tk = "~~";	tk_color = HBBLU;	break;
				case 'D' : tk = "&&";	tk_color = HBYEL;	break;
				default :  tk = "  ";	tk_color = NOR;	break;
			}
			if (legend[1] == 'X') tk = extract(tk,0,0) + "*";
			tk += " ";
			
			if( i==0 && j==0 && !flag )
			{
				if ((string)this_player()->query_env("vt100") == "color")
					str += tk_color;
				str += blink( "<*>" );			
			}
			else {
				if ((string)this_player()->query_env("vt100") == "color")
					str += tk_color;
				str += tk;
			}
		}
		if ((string)this_player()->query_env("vt100") == "color")	str += NOR;
		str += "|\n";
	}
	str += bar;
	if( !flag ) str += 
		sprintf("��Ŀǰ��λ��: (X = %d, Y = %d)\n", x, y);
	write(str);
	return 1;
}
