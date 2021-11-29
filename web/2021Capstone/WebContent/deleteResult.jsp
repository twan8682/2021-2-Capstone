<%@ page language="java" contentType="text/html; charset=utf-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="java.io.*"%>
<%@ include file="dbconn.jsp"%>
<%
String r_id = request.getParameter("r_id");
String picPath = "★경로" + r_id + ".png";
//★절대경로 입력. Invalid escape sequence 오류 발생 시 -> C:\\aJSP\\capstone\\과 같이 작성할 것. (\를 두개)

File f = new File(picPath);
if (f.exists())
	f.delete();

String sql = "select * from result";
PreparedStatement pstmt = conn.prepareStatement(sql);
ResultSet rs = pstmt.executeQuery();

if (rs.next()) {
	sql = "delete from result where r_id=?";
	pstmt = conn.prepareStatement(sql);
	pstmt.setString(1, r_id);
	pstmt.executeUpdate();
} else
	out.println("일치하는 결과 없음.");

if (rs != null)
	rs.close();
if (pstmt != null)
	pstmt.close();
if (conn != null)
	conn.close();

response.sendRedirect("result.jsp");
%>