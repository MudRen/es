//#pragma save_binary
#pragma save_types

/*
 * more.c
 * description: the more command for the player object
 * author: wayfarer
 *
 * Modified by Watcher@TMI (3/27/93) to add done_more() passing and
 * elimination of 100% more prompts.
 */

#include <ansi.h>

protected void search_forward (string arg);
protected void search_reverse (string arg);
protected void even_more(string str);
void do_more_file(object player, string file);

#define CHUNK 24

mixed *files;
string more_file, *lines, last_regexp, chunkstr;
int more_line, from_file, num_lines, direction, chunk;

//  File:    /std/body/wild_card.c
//  Creator: unknown; this "cool" file originated from Portals
//
varargs string *wild_card(object player, string str, int keepdots)
{
	int i, limit;
	string *temp, *pf, work;

	work = resolv_path((string)player->query("cwd"), str);
	if( work == "/" ) return ({ "/" }); /* Special case! Yuck! */

	pf = path_file(work);
	if( pf[0] == "/" ) pf[0] = ""; /* yuck! yet another special case! */
	tell_object(player,"work dir : "+work+"\n");
	temp = get_dir(work);
	tell_object(player,sizeof(temp));
	for ( i = 0 ; i < sizeof(temp) ; i ++ )
		tell_object(player,temp[i]+" !!\n");
	if(!temp) temp = ({});
	temp -= ({ "." });
	temp -= ({ ".." });
	if( !keepdots && (!str || str[0] != '.') )
		temp = filter_array(temp, "remove_dots",this_object());

	for( i=0, limit=sizeof(temp); i<limit; i++ ) {
		tell_object(player,temp[i]+"\n");
		if( file_size(sprintf("%s/%s", pf[0], pf[1])) == -2 ) temp[i] = pf[0];
		else temp[i] = sprintf("%s/%s", pf[0], temp[i]);
	}
	return temp;
}

int remove_dots(string temp)
{
	if( temp[0] == '.' ) return 0;
	return 1;
}

void write_more_line()
{
	printf(set_color("==More==(%s lines of %s)", "HIC"),
		set_color(more_line, "HIG"), set_color(num_lines, "HIY"));
	return;
}


//
varargs int more(object player, mixed str, int flag, int mask)
{
	int i;
	string tmp, hold, hold2;
	string *files2;

	if( !str ) return notify_fail("ʹ�ø�ʽ: more <filename>\n");
	direction = 1;
	last_regexp = "";
	more_line = 0;
	chunkstr = player->getenv("LINES");
	if( !chunkstr || !sscanf(chunkstr, "%d", chunk) ) chunk = CHUNK;
 	chunk--;  		// Make room for the more prompt.
	if( stringp(str) ) {
		from_file = 1;
 		if( !flag ) {
 			files = wild_card(player, str, 1);
 			if( !(i = sizeof(files)) )
 				return notify_fail(i+str+"û���⵵����Ŀ¼��\n");
 			else if( i == 1 && file_size(files[0]) == -2 ) {
 				files = wild_card(player, str + "/*");
 				if( !sizeof(files) )
					return notify_fail("û���κ����ϡ�\n");
			}

			files2 = ({});
			while ( 1 ) {
				for ( i = 0; i < sizeof(files) ; i ++ ) {
					if (sizeof(files[i]) > 0 )
						files2 += ({ files[i] }) ;
					else
						write(files[i]+" is a zero length file !!\n");
				}

				if( !sizeof(files2) )
					return notify_fail("No such file !!\n");
				else
					files = files2 ;
				if( !mask )
					hold = sprintf(":::::::%s:::::::\n\n", files[0]);

				tmp = files[0];
				files -= ({ files[0] }) ;

				if( !hold ) more(player, tmp, 1);
				else {
					if( hold2 = read_file(tmp) )
						more( player, explode(hold, "\n") + explode(hold2,"\n") );
					else
						return notify_fail(sprintf("*����: �㲢û�ж�ȡ�⵵��(%s)��Ȩ��!!\n", tmp));
				}
				return 1;
			}
			return 1;
		}
		do_more_file(player, str);
//		player->done_more();
		return 1;
	}
	else if( pointerp(str) ) lines = str;
	else return notify_fail("Bad argument to more.\n");

	num_lines = sizeof(lines);
	if( !num_lines ) return 1;
	even_more(" ");
	return 1;
}

void do_more_file(object player, string file)
{
	string tmp;

	more_file = file;
	more_line = 0;
	tmp = read_file(more_file);
	if( !stringp(tmp) || tmp == "" ) return;    /* Thanks to Zeus */
	lines = explode(tmp,"\n");
	more( player, lines );
}

varargs void next_more_file(object player, string arg)
{
	string tmp;

	if( !files || sizeof(files) == 0 ) {
//		if( previous ) previous->done_more();
		return;
	}
	if( !arg ) {
		printf("next file:\n:::::::%s:::::::\n", files[0]);
		input_to("next_more_file", 1);
		return;
	}
	tmp = files[0];
	if( sizeof(files) == 1 ) files = ({});
	else files = files[1..(sizeof(files) - 1)];
	do_more_file(player, tmp);
}

protected void even_more(string str)
{
	int i, max;

	if( !str ) str = " ";
	str = str[0..0];
	switch( str ) {
		case " ": break;
		case "":
#if 0
		// if get_char() ever gets fixed we can enable this part and use it
		if( !this_player()->getenv("getchar") ) break;
		write( erase_line() );
		if( more_line >= sizeof(lines) ) return;
		write( lines[more_line]+"\n" );
		more_line++;
		write_more_line();
		input_to("even_more", 1);
		return;
#endif
		break;
    case "b":
    case "B":
    	more_line -= chunk * 2;
    	if( more_line < 0 ) {
    		more_line = chunk - 1;
    		input_to("even_more", 1);
			return;
		}
		break;
	case "<":
		more_line = 0;
		break;
	case ">":
		more_line = sizeof(lines) - chunk;
		break;
	case "!":
		write(erase_line() + "!");
		input_to("exec_cmd");
		return;
		break;
	case "/":
		input_to("search_forward");
		write(erase_line());
		write ("/");
		direction = 1;
		return;
		break;
	case "\\":
		input_to("search_reverse");
		write(erase_line());
		write ("\\");
		direction = 0;
		return;
		break;
	case "n":
		if( !last_regexp || last_regexp == "" ) {
			input_to("even_more", 1);
			return;
		}
		write(erase_line());
		if( direction == 1 ) search_forward(last_regexp);
		else search_reverse(last_regexp);
		return;
		break;
    case "=":
		write(erase_line());
		printf("%d ", more_line);
		input_to("even_more", 1);
		return;
		break;
    case "v":
		write(erase_line());
		write("More for TMI v1.0, written by wayfarer@portals");
		input_to("even_more", 1);
		return;
		break;
    case "h":
    case "?":
		write( clear_screen() );
		write( @HELP_LONG
---------------------------------------------------------------------
               [ ָ��: more - help ���� ]
---------------------------------------------------------------------
    <space>     ��ʾ��һҳ��
    B,b         ��ʾǰһҳ��
    <return>    ��ʾ��һ�С�
    <           �ص��ļ��Ŀ�ͷ��
    >           �Ƶ��ļ��Ľ�β��
    =           ��ʾ����λ���һ�С�
    /           Regexp search forward.
    \           Regexp search backward.
    n           Continue last regexp search. (maintain direction)
    ^L          ������ʾ��Ļ��
    !           ִ�� MUD ������
    v           ӡ���������ơ�
    h,?         ��ʾ help ���档
    Q,q         �뿪��
HELP_LONG
		);
		write_more_line();
		input_to("even_more",1);
		return;
		break;
    case "":
		write(clear_screen());
		write( ESC + "[1;1f");
		more_line -= chunk;
		break;
    case "q":
    case "Q":
		write(erase_line());
		write("\n");
//		player->done_more();
		files = ({ });
		return;
		break;
    default:
		write(erase_line());
		write("Unrecognized command ");
		input_to("even_more", 1);
		return;
		break;
    }
	if( more_line ) write(erase_line());
	for( i=0, max=sizeof(lines); i<chunk; i++ ) {
		if( more_line >= max ) {
			next_more_file();
			return;
		}
		printf("%s\n", lines[more_line]);
		more_line++;
 		if( more_line*100/num_lines >= 100 ) {
 			next_more_file();
 			return;
 		}
    }
	input_to("even_more", 1);
	write_more_line();
	chunkstr = this_object()->getenv("LINES");
	if( !chunkstr || !sscanf(chunkstr, "%d", chunk) ) chunk = CHUNK;
	chunk -= 1;
	return;
}

protected void search_forward(string arg)
{
	string *matches;
	int i, limit;

	matches = regexp(lines[more_line .. (sizeof(lines) - 1)],arg);
	if( !matches || !sizeof(matches) ) {
		write( up_line() + erase_line() + "\n");
		write( inverse("Pattern not found!") );
		input_to("even_more", 1);
		return;
	}
	for( i=more_line, limit=sizeof(lines); i<limit; i++ ) {
		if( matches[0] == lines[i] ) {
			more_line = i;
			write("...skipping\n");
			chunk -= 2;
			even_more(" ");
			last_regexp = arg;
			return;
		}
	}
	return;
}

protected void search_reverse(string arg)
{
	string *matches;
	int i;

	matches = regexp(lines[0 .. (more_line - chunk - 1)],arg);
	if( !matches || !sizeof(matches) ) {
		write( up_line() + erase_line() + "\n" );
		write( inverse("Pattern not found") );
		input_to("even_more", 1);
		return;
	}
	for( i=more_line-chunk-1; i>=0; i-- ) {
		if( matches[sizeof(matches)-1] == lines[i] ) {
			more_line = i;
			even_more(" ");
			last_regexp = arg;
			return;
		}
    }
	return;
}

void exec_cmd(string arg)
{
	this_player()->force_me(arg);
	write(erase_line()+"\n");
	write_more_line();
	input_to("even_more", 1);
}
