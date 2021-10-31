<%@ page language="java" contentType="text/html; charset=utf-8"%>
<%@ page import="java.sql.*"%>
<%@ include file="dbconn.jsp"%>
<%
String r_Id = request.getParameter("r_id");

String sql = "select * from result";
PreparedStatement pstmt = conn.prepareStatement(sql);
ResultSet rs = pstmt.executeQuery();

if (rs.next()) {
	sql = "delete from result where r_id=?";
	pstmt = conn.prepareStatement(sql);
	pstmt.setString(1, r_Id);
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