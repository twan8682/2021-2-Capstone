<%@ page contentType="text/html; charset=utf-8"%>
<%@ page import="java.sql.*" %>
<html>
<head>
<link rel="stylesheet" href="./resources/css/bootstrap.min.css" />
<title>Result</title>
</head>
<body>
<h1>Result</h1>

<table class="table table-hover table-bordered">
 <thead>
   <tr bgcolor = "skyblue">
      <th>시각</th>
      <th>위치</th>
      <th>상태</th>
   </tr>
 </thead>
 <tbody>
 
 	<%@ include file="dbconn.jsp" %>
 	<%
 		PreparedStatement pstmt = null;
 		ResultSet rs = null;
 		String sql = "select * from result";
 		pstmt = conn.prepareStatement(sql);
 		rs = pstmt.executeQuery();
 		while (rs.next()) {
 	%>
 
   <tr>
      <td><%= rs.getString("r_time") %></td>
      <td><%= rs.getString("r_location") %></td>
      <td><%= rs.getString("r_condition") %></td>
   </tr>
   <%
 		}
 	if (rs != null)
 		rs.close();
 	if (pstmt != null)
 		pstmt.close();
 	if (conn != null)
 		conn.close();
   %>
 </tbody> 
</table>
<footer class = "container">
<p>&copy; 2021 Capstone</p>
</footer>
</body>
</html>